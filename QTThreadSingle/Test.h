#pragma once

#include <QWidget>
#include "QTThreadSingle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestClass; };
QT_END_NAMESPACE

class Test : public QWidget
{
	Q_OBJECT

public:
	Test(QWidget *parent = nullptr);
	~Test();
	unsigned int runThread();
public slots:
	void ThreadFinish();
private:
	Ui::TestClass *ui;
	int m_count;
	QTThreadSingle<Test> m_thread;
};
