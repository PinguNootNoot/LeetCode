from collections import OrderedDict

class LRUCache(object):
    def __init__(self, capacity):
        self.cache = OrderedDict()
        self.capacity = capacity


    def get(self, key):
        if key in self.cache:
            self.cache.move_to_end(key,last=True)
            return self.cache[key]
        else:
            return -1


    def put(self, key, value):
        if key in self.cache:
            self.cache[key] = value
            self.cache.move_to_end(key,last=True)
        elif len(self.cache) < self.capacity:
            self.cache[key] = value
        else:
            self.cache.popitem(last=False)
            self.cache[key] = value
