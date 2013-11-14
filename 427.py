import time
import multiprocessing
import sys
from tmp import findL, series

class Consumer(multiprocessing.Process):

    def __init__(self, task_queue, result_queue):
        multiprocessing.Process.__init__(self)
        self.task_queue = task_queue
        self.result_queue = result_queue

    def run(self):
        proc_name = self.name
        while True:
            next_task = self.task_queue.get()
            if next_task is None:
                break
            print '%s %s' % (proc_name, next_task)
            answer = next_task()
            self.result_queue.put(answer)
        return

class Task(object):
    def __init__(self, n):
        self.n = n
    def __call__(self):
        time.sleep(0.1)
        return '%s * %s = %s' % (self.a, self.b, self.a * self.b)

    def __str__(self):
        return 'n = ', self.n


if __name__ == '__main__':
    num = multiprocessing.cpu_count() * 2
    pool = multiprocessing.Pool(processes = num)
    inputs = []
    start = time.time()
    for lst in series(int(sys.argv[1])):
        inputs.append(lst)

    print sum(pool.map(findL, inputs))
    print 'time: ', time.time() - start



    ''''
    tasks = multiprocessing.Queue()
    results = multiprocessing.Queue()

    num = multiprocessing.cpu_count() * 2
    consumers = [Consumer(tasks, results) for i in xrange(num)]

    for c in consumers:
        c.start()

    num_jobs = 10
    for i in xrange(num):
        tasks.put(Task(i, i))

    for i in xrange(num):
        tasks.put(None)

    while num:
        result = results.get()
        print 'result: ', result
        num -= 1'''



