#ifndef MAKEREADYFUTURE_H
#define MAKEREADYFUTURE_H

#include <QFutureInterface>

template <typename T> QFuture<T> makeReadyFuture(T value)
{
	QFutureInterface<T> fi;
	fi.reportResult(std::move(value));
	fi.reportFinished();
	return fi.future();
}

#endif // MAKEREADYFUTURE_H
