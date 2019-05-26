#include <iostream>
#include<string>
#include<vector>

struct Lecture {
    std::string title;
    int duration;
    std::string author;
};

void printLecture(const Lecture& lecture)
{
    std::cout<<"Title: "<<lecture.title<<", duration: "<<lecture.duration<<", author: "<<lecture.author<<"\n";
}

void printCourse(const std::vector<Lecture>lectures)
{
    for(const Lecture &lecture:lectures)
        printLecture(lecture);
}

int main()
{
    Lecture lecture2{"01P",5600,"Sergey"};

    std::vector<Lecture>lectures;
    lectures.push_back({"00P",5400,"Anton"});
    lectures.push_back(lecture2);

    printLecture({"00P",5400,"Anton"});
    printCourse(lectures);

    return 0;
}
