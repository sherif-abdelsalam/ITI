import json

class QueueOutOfRangeException(Exception):
    pass


def load_data():
    with open("queues.json", "r") as f:
        data = json.load(f)
    return data


class BaseQueue:
    def __init__(self):
        self.items = []

    def insert(self, item):
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            return None
        return self.items.pop(0)

    def is_empty(self):
        return len(self.items) == 0


class Queue(BaseQueue):
    all_queues = {} 

    def __init__(self, name, size):
        super().__init__()
        self.name = name
        self.size = size
        Queue.all_queues[name] = self

    def insert(self, item):
        if len(self.items) < self.size:
            super().insert(item)
        else:
            raise QueueOutOfRangeException("Queue is full")   

    def pop(self):
        if not self.is_empty():
            return super().pop()
        print("Warning: Queue is empty!")
        return None


    @classmethod
    def save(cls):
        data = load_data()
        # print(cls.all_queues)
        for name, q in cls.all_queues.items():
            data[name] = q.__dict__ 
            
        with open("queues.json", "w") as f:
            json.dump(data, f, indent=4)

    @classmethod
    def load(cls):
        
        data = load_data()

        #print(data)

        cls.all_queues = {}

        for name, attrs in data.items():
            q = cls(attrs["name"], attrs["size"])
            q.items = attrs["items"] 
            cls.all_queues[name] = q


if __name__ == "__main__":

    q1 = Queue("q1", 3)
    q1.insert(10)
    q1.insert(20)
    q1.insert(30)

    q2 = Queue("q2", 2)
    q2.insert("a")
    q2.insert("b")  

    q3 = Queue("q3", 4)
    q3.insert("x")
    q3.insert("z")



    queue.save()


    queue.load()



    
