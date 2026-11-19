#include <iostream>
#include <vector>
using namespace std;

int& highestMark(int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
            highest = i;
    }

    return marks[highest];
}

const int& highestMarkConst(const int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
            highest = i;
    }

    return marks[highest];
}

int highestMarkCopy(const int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
            highest = i;
    }

    return marks[highest];
}

int highestMarkIndex(const int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
            highest = i;
    }

    return highest;
}

int main()
{
    int marks[] = {75, 88, 92, 81, 85};
    int size = 5;

    cout << "Original highest mark: " << highestMark(marks, size) << '\n';

    highestMark(marks, size) += 2;

    cout << "After moderation: " << highestMark(marks, size) << '\n';

    cout << "Const reference: "
         << highestMarkConst(marks, size) << '\n';

    cout << "Returned copy: "
         << highestMarkCopy(marks, size) << '\n';

    int index = highestMarkIndex(marks, size);
    cout << "Highest mark index: " << index << '\n';

    marks[index] += 1;

    cout << "After index modification: " << marks[index] << '\n';

    vector<int> growingMarks = {70, 80, 90};

    int& savedReference = growingMarks[2];

    cout << "Before vector growth: " << savedReference << '\n';

    growingMarks.push_back(95);

    cout << "After vector growth, use a fresh access: "
         << growingMarks[3] << '\n';

    return 0;
}
