#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "data/Concert.h"
#include "data/Movie.h"
#include "data/TvShow.h"
#include "globals/Globals.h"

class Movie;

/**
 * @brief The Filter class
 */
class Filter
{
public:
    explicit Filter(QString text, QString shortText, QStringList filterText, int info, bool hasInfo);
    bool accepts(QString text) const;
    bool accepts(Movie *movie);
    bool accepts(Concert *concert);
    bool accepts(TvShow *show);
    QString text() const;
    QString shortText() const;
    int info() const;
    void setShortText(QString shortText);
    void setText(QString text);
private:
    QString m_text;
    QString m_shortText;
    QStringList m_filterText;
    int m_info;
    bool m_hasInfo;
};

#endif // FILTER_H
