#ifndef TEXT2SPEECH_H
#define TEXT2SPEECH_H

#include <QMainWindow>
#include <QVoice>
#include <QDebug>
#include <QTextToSpeech>
#include <QMessageBox>

namespace TS_LANGAUAGE {
enum {
    ENGLISH = 0,
    HINDI,
    MARATHI,
    BENGALI,
    KANNADA,
    MALAYALAM,
    TAMIL,
    TELUGU,
    NEPALI,
    JAPANESE,
    FRENCH
};
}

QT_BEGIN_NAMESPACE
namespace Ui { class Text2Speech; }
QT_END_NAMESPACE

class Text2Speech : public QMainWindow
{
    Q_OBJECT

public:
    Text2Speech(QWidget *parent = nullptr);
    ~Text2Speech();
private slots:
    void sl_stateChanged(QTextToSpeech::State txtState);
    void on_pushButton_speech_clicked();
    void on_comboBox_Language_currentIndexChanged(int index);
private:
    Ui::Text2Speech *ui;
    QStringList strLangs = {"English", "Hindi", "Marathi","Bengali", "Kannada", "Malayalam", "Tamil", "Telugu"
                           , "Nepali", "Japanese", "French"};
    QTextToSpeech *speech = 0;
    QVector<QVoice> voices;
    void m_ChangeLanguage(int lang_id);
};
#endif // TEXT2SPEECH_H
