#ifndef QTMEGAREQUESTLISTENER_H
#define QTMEGAREQUESTLISTENER_H

#include <QObject>
#include "megaapi.h"

namespace mega
{
class QTMegaRequestListener : public QObject, public MegaRequestListener
{
	Q_OBJECT

public:
    QTMegaRequestListener(MegaApi *megaApi, MegaRequestListener *listener = NULL);
    virtual ~QTMegaRequestListener();

	//Request callbacks
	virtual void onRequestStart(MegaApi* api, MegaRequest *request);
	virtual void onRequestFinish(MegaApi* api, MegaRequest *request, MegaError* e);
    virtual void onRequestUpdate(MegaApi* api, MegaRequest *request);
	virtual void onRequestTemporaryError(MegaApi *api, MegaRequest *request, MegaError* e);

signals:
	void QTonRequestStartSignal(MegaApi* api, MegaRequest *request);
	void QTonRequestFinishSignal(MegaApi* api, MegaRequest *request, MegaError* e);
    void QTonRequestUpdateSignal(MegaApi* api, MegaRequest *request);
	void QTonRequestTemporaryErrorSignal(MegaApi *api, MegaRequest *request, MegaError* e);

public slots:
	virtual void QTonRequestStart(MegaApi* api, MegaRequest *request);
	virtual void QTonRequestFinish(MegaApi* api, MegaRequest *request, MegaError* e);
    virtual void QTonRequestUpdate(MegaApi* api, MegaRequest *request);
	virtual void QTonRequestTemporaryError(MegaApi *api, MegaRequest *request, MegaError* e);

protected:
	MegaRequestListener *listener;
    MegaApi *megaApi;
};
}

#endif // QTMEGAREQUESTLISTENER_H
