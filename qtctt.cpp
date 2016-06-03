#include "qtctt.h"
#include "proj_api.h"

QtCTT::QtCTT(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.actionTransfer,SIGNAL(triggered()),this,SLOT(slot_transfer()));
}

QtCTT::~QtCTT()
{

}

void QtCTT::slot_transfer()
{
		//TODO: need check
		double lon=ui.le_srcLon->text().toDouble();
		double lat=ui.le_srcLat->text().toDouble();
		double height=ui.le_srcH->text().toDouble();
		//e.g.
		//double lon=103.33;
		//double lat=41.44;
		//double height=500;

		QString qsSrc= ui.le_srcCS->text();
		QString qsDst =  ui.le_dstCS->text();
        	//e.g.
		// QString qsSrc = "+proj=longlat +datum=WGS84 +no_defs";
	   	// QString qsDst = "+proj=tmerc +lat_0=0 +lon_0=105 +k=1 +x_0=18500000 +y_0=0 +ellps=krass +units=m +no_defs  +towgs84=0,0,0,0,0,0,0";
	     
		projPJ src = pj_init_plus(qsSrc.toStdString().c_str());
		projPJ dst = pj_init_plus(qsDst.toStdString().c_str());
		if (src == NULL || dst == NULL)
		{
			return;
		}
		
		lon*=DEG_TO_RAD;
		lat*=DEG_TO_RAD;
		
		int flag=pj_transform(src,dst,1,1,&lon,&lat,&height);
		
        	pj_free(src);
		pj_free(dst);

		ui.le_dstLon->setText(QString::number(lon,'f',8));
		ui.le_dstLat->setText(QString::number(lat,'f',8));
		ui.le_dstH->setText(QString::number(height,'f',8));
}
