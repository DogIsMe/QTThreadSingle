# QTThreadSingle
qt simple threads run their own class functions. All you need is the header file.

在qt类里使用 test是qt类
声明：
QTThreadSingle<Test> m_thread;
使用
	m_thread.SetCallData(this, &Test::runThread);
	m_thread.start();

runThread是类里的函数unsigned int runThread();可以随意写

运行结束会触发线程完成槽可以忽略，可以使用返回值
	connect(&m_thread, &QThread::finished,this, &Test::ThreadFinish);
	m_thread.GetExitCode();