#include "Test.h"
#include "ui_Test.h"
Test::Test(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TestClass())
{
	ui->setupUi(this);
	connect(&m_thread, &QThread::finished,this, &Test::ThreadFinish);
	m_thread.SetCallData(this, &Test::runThread);
	m_thread.start();
}

Test::~Test()
{
	delete ui;
}

unsigned int Test::runThread()
{
	while (m_count < 1000)
	{
		m_count++;
	}
	return 0;
}
void Test::ThreadFinish()
{
	m_thread.GetExitCode();

}