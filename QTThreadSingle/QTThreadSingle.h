#ifndef QTTHREADSINGLE__H__
#define QTTHREADSINGLE__H__

#include <QThread>
template<class T>
class QTThreadSingle : public QThread
{
public:
	typedef unsigned int(T::* ClassFun)();

	QTThreadSingle(QObject* parent = nullptr);
	~QTThreadSingle();

	void SetCallData(T* pObject, ClassFun fun);
	unsigned int GetExitCode() const;
protected:
	void run() override;

private:
	ClassFun m_fun;
	T* p_object;
	unsigned int m_retCode;
};

template<class T>
QTThreadSingle<T>::QTThreadSingle(QObject* parent)
	: QThread(parent), m_fun(nullptr),
	p_object(nullptr),
	m_retCode(0)

{

}
template<class T>
QTThreadSingle<T>::~QTThreadSingle()
{
	wait(10000);
}
template<class T>
void QTThreadSingle<T>::SetCallData(T* pObject, ClassFun fun)
{
	p_object = pObject;
	m_fun = fun;
}
template<class T>
void QTThreadSingle<T>::run()
{
	if (p_object && m_fun)
	{
		m_retCode = (p_object->*m_fun)();
	}
}

template<class T>
unsigned inline int QTThreadSingle<T>::GetExitCode() const
{
	return m_retCode;
}
#endif // !QTTHREADSINGLE__H__