#include "ImageLabel.h"
#include "ui_ImageLabel.h"

/**
 * @brief ImageLabel::ImageLabel
 * @param parent
 */
ImageLabel::ImageLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageLabel)
{
    ui->setupUi(this);
    ui->resolution->setText("");
    QFont font = ui->resolution->font();
#ifdef Q_OS_WIN32
    font.setPointSize(font.pointSize()-1);
#else
    font.setPointSize(font.pointSize()-2);
#endif
    ui->resolution->setFont(font);
}

/**
 * @brief ImageLabel::~ImageLabel
 */
ImageLabel::~ImageLabel()
{
    delete ui;
}

/**
 * @brief Sets the image to show
 * @param pixmap QPixmap of the image
 */
void ImageLabel::setImage(QPixmap img)
{
    ui->image->setPixmap(img);
}

/**
 * @brief Sets the resolution text
 * @param resolution Resolution (QSize) to set
 * @param hint Hint
 */
void ImageLabel::setHint(QSize resolution, QString hint)
{
    QString text;
    if (!resolution.isNull() && !resolution.isEmpty() && resolution.isValid())
        text = QString("%1 x %2").arg(resolution.width()).arg(resolution.height());
    text.append(hint);
    ui->resolution->setText(text);
}

QImage ImageLabel::image() const
{
    return ui->image->pixmap()->toImage();
}
