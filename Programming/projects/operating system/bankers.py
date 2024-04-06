class Process:
    def __init__(self, max_resources):
        self.max_resources = max_resources
        self.allocated_resources = [0]*len(max_resources)

class BankersAlgorithm:
    def __init__(self, available_resources):
        self.available_resources = available_resources
        self.processes = []

    def add_process(self, max_resources):
        if any(i > j for i, j in zip(max_resources, self.available_resources)):
            print("Error: process requires more resources than available.")
            return
        self.processes.append(Process(max_resources))

    def request_resources(self, process_index, request):
        if any(i > j for i, j in zip(request, self.processes[process_index].max_resources)):
            print("Error: process requested more resources than maximum declared.")
            return False
        if any(i > j for i, j in zip(request, self.available_resources)):
            print("Error: process requested more resources than available.")
            return False
        self.available_resources = [i - j for i, j in zip(self.available_resources, request)]
        self.processes[process_index].allocated_resources = [i + j for i, j in zip(self.processes[process_index].allocated_resources, request)]
        if not self.is_safe_state():
            self.available_resources = [i + j for i, j in zip(self.available_resources, request)]
            self.processes[process_index].allocated_resources = [i - j for i, j in zip(self.processes[process_index].allocated_resources, request)]
            print("Error: resource request leads to unsafe state.")
            return False
        return True

    def is_safe_state(self):
        work = self.available_resources.copy()
        finish = [False]*len(self.processes)
        while True:
            for i, process in enumerate(self.processes):
                if not finish[i] and all(i <= j for i, j in zip(process.max_resources, work)):
                    work = [i + j for i, j in zip(work, process.allocated_resources)]
                    finish[i] = True
                    break
            else:
                break
        if all(finish):
            return True
        else:
            return False

# Usage
ba = BankersAlgorithm([10, 5, 7])
ba.add_process([7, 5, 3])
ba.add_process([3, 2, 2])
ba.add_process([9, 0, 2])
ba.add_process([2, 2, 2])
ba.add_process([4, 3, 3])
print(ba.request_resources(1, [1, 0, 2]))  # True
print(ba.request_resources(4, [0, 2, 0]))  # False