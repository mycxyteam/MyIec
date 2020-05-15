#include "myiec.h"
#include <QApplication>
#include <QDebug>
#include <thread>
#include <synchapi.h>
#include <mutex>

//#define threadDebug   //用于显著了解多线程的内存使用

#ifdef threadDebug
int increat(int *p,int times,std::mutex &mtx)
{
    for(int i=0;i < times; i++){
 //      mtx.lock();
        ++*p;
   //     mtx.unlock();
        qDebug()<<"1";
//        Sleep(1000);
    }
    return 0;
}
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyIec w;
    w.show();
#ifdef threadDebug
    int num = 0;
    std::mutex mtx;
    std::thread thread1([&](){
        increat(&num,10,mtx);
    });
//    std::thread thread2(increat,&num,1000);
    std::thread thread2([&](){
        for(int i=0;i<10;i++){
        //    mtx.lock();
            ++num;
        //    mtx.unlock();
            qDebug()<<"2";
 //           Sleep(1000);
        }
    });
    thread1.join();
    thread2.join();
    qDebug()<< "num" << num;
#endif
#ifdef pythonDebug
    //初始化 python模块
    Py_Initialize();
    if(!Py_IsInitialized())
    {
        return -1;
    }
    PyObject *pModule = PyImport_ImportModule("hello.py");
    if(!pModule)
    {
        return -1;
    }
    PyObject *pfunHello = PyObject_GetAttrString(pModule,"hello");

    PyObject_CallFunction(pfunHello,NULL);

    Py_Finalize();
#endif

    return a.exec();
}
