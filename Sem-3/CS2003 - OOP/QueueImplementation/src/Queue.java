class Queue {
    private int front, rear, capacity;
    private int queue[];

    public Queue(int size) {
        front = rear = 0;
        capacity = size;
        queue = new int[capacity];
    }

    public void enqueue(int val) {
        if (capacity == rear) {
            System.out.println("Queue is full");
        }
        else {
            queue[rear] = val;
            rear++;
        }
    }

    public void dequeue() {
        if (front == rear) {
            System.out.println("Queue is empty");
        }
        else {
            for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }
            if (rear < capacity) {
                queue[rear - 1] = 0;
            }
            rear--;
        }
    }

    public void display() {
        if (front == rear) {
            System.out.println("Queue is empty");
            return;
        }

        for (int i = front; i < rear; i++) {
            System.out.print(queue[i] + " ");
        }
        System.out.println();
    }

    public void front() {
        if (front == rear) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.println("Front element is: " + queue[front]);
    }

    public static void main(String[] args) {
        Queue q = new Queue(5);
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        System.out.println("Queue elements after enqueuing 5 elements:");
        q.display();
        q.dequeue();
        q.dequeue();
        System.out.println("Queue elements after dequeuing 2 elements:");
        q.display();
        q.front();
    }
}
