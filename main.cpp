#include <QtCore/QCoreApplication>
#include "QThread"
#include <vector>
#include <iostream>
using namespace std;

// QThread ∂¿¡¢œÓ≤‚ ‘

class MyThread : public QThread
{
public:
    MyThread(vector<int> vec)
        : m_vec(std::move(vec))
    {}
    virtual ~MyThread() {};
protected:
    virtual void run();
private:
    vector<int> m_vec;
};

void MyThread::run()
{
    foreach(const auto& v, m_vec)
    {
        cout << v << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> v1{ 1,2,3,4,5 };
    vector<int> v2{ 11,12,13,14,15 };
    for (int nIndex = 0; nIndex < 2; ++nIndex)
    {
        MyThread* t = new MyThread(nIndex == 1 ? v1 : v2);
        t->start();
    }

    return a.exec();
}
