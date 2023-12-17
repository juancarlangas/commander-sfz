#pragma once

#include <QString>
#include <qglobal.h>
#include <QVector>
	
struct Combi {
	QVector<QString> parts;
};

class Instrument {
	private:
		qint16 n_sound_banks;
		QVector<QVector<QString>> sounds;

		qint16 n_combi_banks;
		qint16 parts_per_combi;
		QVector<QVector<Combi>> combis;

		qint16 current_scene;
};
