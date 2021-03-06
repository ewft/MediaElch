#ifndef FANARTTVMUSIC_H
#define FANARTTVMUSIC_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include "globals/Globals.h"
#include "data/ImageProviderInterface.h"
#include "scrapers/TMDb.h"
#include "scrapers/TheTvDb.h"

class FanartTvMusic : public ImageProviderInterface
{
    Q_OBJECT
public:
    explicit FanartTvMusic(QObject *parent = 0);
    QString name();
    QUrl siteUrl();
    QString identifier();
    void movieImages(Movie *movie, QString tmdbId, QList<int> types);
    void moviePosters(QString tmdbId);
    void movieBackdrops(QString tmdbId);
    void movieLogos(QString tmdbId);
    void movieBanners(QString tmdbId);
    void movieThumbs(QString tmdbId);
    void movieClearArts(QString tmdbId);
    void movieCdArts(QString tmdbId);
    void concertImages(Concert *concert, QString tmdbId, QList<int> types);
    void concertPosters(QString tmdbId);
    void concertBackdrops(QString mbId);
    void concertLogos(QString mbId);
    void concertClearArts(QString tmdbId);
    void concertCdArts(QString tmdbId);
    void tvShowImages(TvShow *show, QString tvdbId, QList<int> types);
    void tvShowPosters(QString tvdbId);
    void tvShowBackdrops(QString tvdbId);
    void tvShowLogos(QString tvdbId);
    void tvShowClearArts(QString tvdbId);
    void tvShowCharacterArts(QString tvdbId);
    void tvShowBanners(QString tvdbId);
    void tvShowEpisodeThumb(QString tvdbId, int season, int episode);
    void tvShowSeason(QString tvdbId, int season);
    void tvShowSeasonBanners(QString tvdbId, int season);
    void tvShowSeasonBackdrops(QString tvdbId, int season);
    void tvShowThumbs(QString tvdbId);
    void tvShowSeasonThumbs(QString tvdbId, int season);
    void artistFanarts(QString mbId);
    void artistLogos(QString mbId);
    void artistThumbs(QString mbId);
    void albumCdArts(QString mbId);
    void albumThumbs(QString mbId);
    void artistImages(Artist *artist, QString mbId, QList<int> types);
    void albumImages(Album *album, QString mbId, QList<int> types);
    void albumBooklets(QString mbId);
    QList<int> provides();
    bool hasSettings();
    void loadSettings(QSettings &settings);
    void saveSettings(QSettings &settings);
    QWidget *settingsWidget();

public slots:
    void searchMovie(QString searchStr, int limit = 0);
    void searchConcert(QString searchStr, int limit = 0);
    void searchTvShow(QString searchStr, int limit = 0);
    void searchArtist(QString searchStr, int limit = 0);
    void searchAlbum(QString artistName, QString searchStr, int limit = 0);

signals:
    void sigSearchDone(QList<ScraperSearchResult>);
    void sigImagesLoaded(QList<Poster>);
    void sigImagesLoaded(Movie *, QMap<int, QList<Poster> >);
    void sigImagesLoaded(Concert *, QMap<int, QList<Poster> >);
    void sigImagesLoaded(TvShow *, QMap<int, QList<Poster> >);
    void sigImagesLoaded(Artist *, QMap<int, QList<Poster> >);
    void sigImagesLoaded(Album *, QMap<int, QList<Poster> >);

private slots:
    void onSearchArtistFinished();
    void onLoadArtistFinished();
    void onSearchAlbumFinished();
    void onLoadAlbumFinished();
    void onLoadAllArtistDataFinished();
    void onLoadAllAlbumDataFinished();

private:
    QList<int> m_provides;
    QString m_apiKey;
    QString m_personalApiKey;
    QNetworkAccessManager m_qnam;
    int m_searchResultLimit;
    QString m_language;

    QNetworkAccessManager *qnam();
    QList<Poster> parseData(QString json, int type);
    QString keyParameter();
};

#endif // FANARTTVMUSIC_H
