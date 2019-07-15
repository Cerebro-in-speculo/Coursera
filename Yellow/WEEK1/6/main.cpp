#include<iostream>
#include<map>
#include<string>
#include<tuple>

using namespace std;

//enum class TaskStatus {
//	NEW,          
//	IN_PROGRESS,  
//	TESTING,      
//	DONE          
//};
//
//using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:

	const TasksInfo& GetPersonTasksInfo(const string& person) const
	{
			return personsTasks.at(person);
	}

	void AddNewTask(const string& person)
	{
		++personsTasks[person][TaskStatus::NEW];
	}

	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
	{
		TasksInfo real_temp;
		TasksInfo untouched_temp;
		TasksInfo updated_temp;
		TasksInfo temp = personsTasks[person];

		for (auto& i : temp)
		{
			switch (i.first)
			{
				case TaskStatus::NEW:
				{
					if (i.second > 0)
					{
						int count = i.second;
						while (count > 0 && task_count > 0)
						{
							real_temp[TaskStatus::IN_PROGRESS]++;
							updated_temp[TaskStatus::IN_PROGRESS]++;
							--count;
							--task_count;
						}
						if (count > 0)
						{
							real_temp[TaskStatus::NEW]+=count;
							untouched_temp[TaskStatus::NEW]+=count;
						}
					}
					break;
				}
				case TaskStatus::IN_PROGRESS:
				{
					if (i.second > 0)
					{
						int count = i.second;
						while (count > 0 && task_count > 0)
						{
							real_temp[TaskStatus::TESTING]++;
							updated_temp[TaskStatus::TESTING]++;
							--count;
							--task_count;
						}
						if (count > 0)
						{
							real_temp[TaskStatus::IN_PROGRESS] += count;
							untouched_temp[TaskStatus::IN_PROGRESS] += count;
						}
					}
					break;
				}
				case TaskStatus::TESTING:
				{
					if (i.second > 0)
					{
						int count = i.second;
						while (count > 0 && task_count > 0)
						{
							real_temp[TaskStatus::DONE]++;
							updated_temp[TaskStatus::DONE]++;
							--count;
							--task_count;
						}
						if (count > 0)
						{
							real_temp[TaskStatus::TESTING] += count;
							untouched_temp[TaskStatus::TESTING] += count;
						}
					}
					break;
				}
				case TaskStatus::DONE:
				{
					if (i.second > 0)
					{
						real_temp[TaskStatus::DONE] += i.second;
					}
					break;
				}
			}
		}
		personsTasks[person]=real_temp;
		return tuple<TasksInfo, TasksInfo>(updated_temp, untouched_temp);
	}
private:
	TasksInfo taskStatus;
	map<string, TasksInfo>personsTasks;
};

//void PrintTasksInfo(TasksInfo tasks_info)
//{
//	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
//		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
//		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
//		", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
//}
//
//void PrintTasksInfo(const TasksInfo& updated_tasks, const TasksInfo& untouched_tasks) {
//    std::cout << "Updated: [";
//    PrintTasksInfo(updated_tasks);
//    std::cout << "] ";
//
//    std::cout << "Untouched: [";
//    PrintTasksInfo(untouched_tasks);
//    std::cout << "] ";
//
//    std::cout << std::endl;
//}

//int main()
//{
//	TeamTasks tasks;
//	TasksInfo updated_tasks;
//	TasksInfo untouched_tasks;
//
//	/* TEST 1 */
//	std::cout << "Alice" << std::endl;
//
//	for (auto i = 0; i < 5; ++i) {
//		tasks.AddNewTask("Alice");
//	}
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
//	PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]
//
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
//	PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]
//
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
//	PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]
//
//	for (auto i = 0; i < 5; ++i) {
//		tasks.AddNewTask("Alice");
//	}
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice",
//		2);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]
//	PrintTasksInfo(updated_tasks, untouched_tasks);
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
//	std::cout << std::endl;
//
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
//	PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
//	std::cout << std::endl;
//
//	/* TEST 2 */
//	std::cout << "\nJack" << std::endl;
//
//	tasks.AddNewTask("Jack");
//
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 1);
//	PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]
//
//	tasks.AddNewTask("Jack");
//
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 2);
//	PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1, "TESTING": 1}, {}]
//
//	tasks.AddNewTask("Jack");
//
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));  // {"NEW": 1, "IN_PROGRESS": 1, "TESTING": 1, "DONE": 0}
//	std::cout << std::endl;
//
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Jack", 3);
//	PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1, "TESTING": 1, "DONE": 1}, {}]
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Jack"));  // {"IN_PROGRESS": 1, "TESTING": 1, "DONE": 1}
//	std::cout << std::endl;
//
//	///* TEST 3 */
//	//std::cout << "\nLisa" << std::endl;
//
//	//for (auto i = 0; i < 5; ++i) {
//	//	tasks.AddNewTask("Lisa");
//	//}
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 1);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]
//
//	//for (auto i = 0; i < 5; ++i) {
//	//	tasks.AddNewTask("Lisa");
//	//}
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]
//
//	//PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
//	//std::cout << std::endl;
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 4);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]
//
//	//PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
//	//std::cout << std::endl;
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 4, "DONE": 1}, {"TESTING": 4}]
//
//	//PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"TESTING": 8, "DONE": 2}
//	//std::cout << std::endl;
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 8}, {}]
//
//	//PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
//	//std::cout << std::endl;
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]
//
//	//PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
//	//std::cout << std::endl;
//
//	//tasks.AddNewTask("Lisa");
//
//
//	//PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 1, "DONE": 10}
//	//std::cout << std::endl;
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]
//
//	//PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 1, "DONE": 10}
//	//std::cout << std::endl;
//
//	//tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Bob", 3);
//	//PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]
//
//
//	return 0;
//}
