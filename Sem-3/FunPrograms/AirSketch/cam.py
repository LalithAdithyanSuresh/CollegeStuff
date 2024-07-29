# hand_tracker.py
import cv2
import mediapipe as mp

class HandTracker:
    def __init__(self, max_num_hands=1, min_detection_confidence=0.7, min_tracking_confidence=0.6):
        self.vid = cv2.VideoCapture(0)
        self.vid.set(3, 1280)
        self.vid.set(4, 720)
        self.mphands = mp.solutions.hands
        self.hands = self.mphands.Hands(max_num_hands=max_num_hands,
                                        min_detection_confidence=min_detection_confidence,
                                        min_tracking_confidence=min_tracking_confidence)
        self.mpdraw = mp.solutions.drawing_utils

    def process_frame(self):
        _, frame = self.vid.read()
        RGBframe = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        result = self.hands.process(RGBframe)
        if result.multi_hand_landmarks:
            for handLm in result.multi_hand_landmarks:
                self.mpdraw.draw_landmarks(frame, handLm, self.mphands.HAND_CONNECTIONS,
                                           self.mpdraw.DrawingSpec(color=(0, 0, 255), circle_radius=7, thickness=cv2.FILLED),
                                           self.mpdraw.DrawingSpec(color=(0, 255, 0), thickness=7))
                for id, lm in enumerate(handLm.landmark):
                    h, w, _ = frame.shape
                    cx, cy = int(lm.x * w), int(lm.y * h)
                    print(id, cx, cy)
        return frame

    def release(self):
        self.vid.release()
        cv2.destroyAllWindows()

if __name__ == "__main__":
    hand_tracker = HandTracker()
    while True:
        frame = hand_tracker.process_frame()
        cv2.imshow("video", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    hand_tracker.release()