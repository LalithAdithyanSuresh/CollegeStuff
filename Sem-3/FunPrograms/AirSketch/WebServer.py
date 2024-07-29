# app.py
import streamlit as st
import cv2
from cam import HandTracker
import av
from streamlit_webrtc import webrtc_streamer, VideoTransformerBase

class VideoTransformer(VideoTransformerBase):
    def __init__(self):
        self.hand_tracker = HandTracker()

    def transform(self, frame):
        img = frame.to_ndarray(format="bgr24")
        img = self.hand_tracker.process_frame(img)
        return av.VideoFrame.from_ndarray(img, format="bgr24")

webrtc_streamer(key="example", video_transformer_factory=VideoTransformer)

st.title("Hand Tracking with MediaPipe and Streamlit")
st.write("This application tracks hands in real-time using MediaPipe and OpenCV.")
