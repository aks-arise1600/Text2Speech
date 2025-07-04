#include "Text2Speech.h"
#include "ui_Text2Speech.h"

Text2Speech::Text2Speech(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Text2Speech)
{
    ui->setupUi(this);

    ui->comboBox_Language->addItems(strLangs);

    speech = new QTextToSpeech;
    connect(speech, SIGNAL(stateChanged(QTextToSpeech::State)), this, SLOT(sl_stateChanged(QTextToSpeech::State)));

    m_ChangeLanguage(ui->comboBox_Language->currentIndex());


}

Text2Speech::~Text2Speech()
{
    delete ui;
}

void Text2Speech::sl_stateChanged(QTextToSpeech::State txtState)
{
    switch (txtState) {
    case QTextToSpeech::Ready:
        qDebug() <<"Ready";
        break;
    case QTextToSpeech::Speaking:
        qDebug() <<"Speaking";
        break;
    case QTextToSpeech::Paused:
        qDebug() <<"Paused";
        break;
    case QTextToSpeech::BackendError:
        qDebug() <<"BackendError";
        break;
    default:
        qDebug() <<"Unknown";
        break;
    }
}


void Text2Speech::on_pushButton_speech_clicked()
{
    if(speech && ui->textEdit->toPlainText().size()>0)
    {
        speech->setVoice(voices.at(ui->comboBox_voice->currentIndex()));
        speech->say(ui->textEdit->toPlainText());
    }
    else
        QMessageBox::warning(this,"Error","Unable to convert in speech !");
}

void Text2Speech::m_ChangeLanguage(int lang_id)
{
    if(!speech)
        return;
    bool isUpdated = false;
    switch (lang_id) {
    case TS_LANGAUAGE::ENGLISH:
    {
        QLocale locale(QLocale::English, QLocale::UnitedStates);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::HINDI:
    {
        QLocale locale(QLocale::Hindi, QLocale::India);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::MARATHI:
    {
        QLocale locale(QLocale::Marathi, QLocale::India);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::BENGALI:
    {
        QLocale locale(QLocale::Bengali, QLocale::Bangladesh);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::KANNADA:
    {
        QLocale locale(QLocale::Kannada, QLocale::India);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::MALAYALAM:
    {
        QLocale locale(QLocale::Malayalam, QLocale::India);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::TAMIL:
    {
        QLocale locale(QLocale::Tamil, QLocale::India);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::TELUGU:
    {
        QLocale locale(QLocale::Telugu, QLocale::India);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::NEPALI:
    {
        QLocale locale(QLocale::Nepali, QLocale::Nepal);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::JAPANESE:
    {
        QLocale locale(QLocale::Japanese, QLocale::Japan);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    case TS_LANGAUAGE::FRENCH:
    {
        QLocale locale(QLocale::French, QLocale::France);
        speech->setLocale(locale);
        isUpdated = true;
    }
        break;
    }

    if(isUpdated)
    {
        voices.clear();
        QStringList vList;
        voices = speech->availableVoices();
        for (int indx = 0; indx < voices.size(); indx++)
        {
            qDebug() <<indx+1 << "Voice:" << voices.at(indx).name();
            vList << voices.at(indx).name();
        }
        ui->comboBox_voice->clear();
        ui->comboBox_voice->addItems(vList);
    }
}


void Text2Speech::on_comboBox_Language_currentIndexChanged(int index)
{
    m_ChangeLanguage(index);
}

