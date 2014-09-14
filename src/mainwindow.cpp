#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    installEventFilter(this);

    cameraIsOpened=false;
    mouseButtonClicked=false;
    colorMode = false;
    firstPointSelectedIsValid=false;
    imProcDataAvailable=false;

    stallMode = false;

    permissionForSending = false;

    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);

    semaphore=new QSemaphore(1);
    semaphoreForColorImage = new QSemaphore(1);
    access2StallMode = new QSemaphore(1);

    QStringList items;
    items<<"0"<<"1"<<"Network";
    ui->cam_comboBox->addItems(items);

    QStringList fps_items;
    fps_items<<"15"<<"30"<<"60";
    ui->fps_comboBox->addItems(fps_items);

    QPalette red_pal(Qt::red);
    ui->redSelect_button->setAutoFillBackground(true);
    ui->redSelect_button->setPalette(red_pal);

    QPalette blue_pal(Qt::blue);
    ui->blueSelect_button->setAutoFillBackground(true);
    ui->blueSelect_button->setPalette(blue_pal);

    QPalette green_pal(Qt::green);
    ui->greenSelect_button->setAutoFillBackground(true);
    ui->greenSelect_button->setPalette(green_pal);

    QPalette yellow_pal(Qt::yellow);
    ui->yellowSelect_button->setAutoFillBackground(true);
    ui->yellowSelect_button->setPalette(yellow_pal);

    QPalette purple_pal(QColor(148,0,211));
    ui->violetSelect_button->setAutoFillBackground(true);
    ui->violetSelect_button->setPalette(purple_pal);

    QPalette cyan_pal(Qt::cyan);
    ui->cyanSelect_button->setAutoFillBackground(true);
    ui->cyanSelect_button->setPalette(cyan_pal);

    QPalette black_pal(Qt::black);
    ui->blackSelect_button->setAutoFillBackground(true);
    ui->blackSelect_button->setPalette(black_pal);

    cam_timer = new QTimer();
    send_timer = new QTimer();
    camSetting = new cameraSetting();

    connect(this,SIGNAL(imageReady(Mat)),this,SLOT(callImageProcessingFunctions(Mat)));
    connect(this,SIGNAL(cameraSettingChanged()),this,SLOT(updateCameraSetting()));

    imageProcessor=new ImageProcessing();

    //openSetting("/home/kn2c/setting.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_button_clicked()
{
    Mat frame;

    if(ui->cam_comboBox->currentText() == "Network")
    {
    }
    else
    {
        if(ui->cam_comboBox->currentText()=="0")
        {
            cameraIsOpened=cap.open(CAP_FIREWIRE+0);
        }
        else
        {
            cameraIsOpened=cap.open(CAP_FIREWIRE+1);
        }

        setCameraSetting();

        cap.read(frame);

        cam_timer->start(1000*(1/ui->fps_comboBox->currentText().toInt()));
        connect(cam_timer,SIGNAL(timeout()),this,SLOT(cam_timeout()));
    }

    emit imageReady(frame);
}

void MainWindow::cam_timeout()
{
    Mat frame;
    cap.read(frame);
    emit imageReady(frame);
}

void MainWindow::enableCameraSetting()
{
    ui->red_slider->setEnabled(true);
    ui->blue_slider->setEnabled(true);
    ui->exposure_slider->setEnabled(true);
    ui->brightness_slider->setEnabled(true);
    ui->gain_slider->setEnabled(true);
    ui->sharpness_slider->setEnabled(true);

    ui->red_label->setEnabled(true);
    ui->blue_label->setEnabled(true);
    ui->expo_label->setEnabled(true);
    ui->brightness_label->setEnabled(true);
    ui->gain_label->setEnabled(true);
    ui->sharpness_label->setEnabled(true);

    ui->redOut_label->setEnabled(true);
    ui->blueOut_label->setEnabled(true);
    ui->expoOut_label->setEnabled(true);
    ui->brightnessOut_label->setEnabled(true);
    ui->gainOut_label->setEnabled(true);
    ui->sharpnessOut_label->setEnabled(true);
}

void MainWindow::disableCameraSetting()
{
    ui->red_slider->setDisabled(true);
    ui->blue_slider->setDisabled(true);
    ui->exposure_slider->setDisabled(true);
    ui->brightness_slider->setDisabled(true);
    ui->gain_slider->setDisabled(true);
    ui->sharpness_slider->setDisabled(true);

    ui->red_label->setDisabled(true);
    ui->blue_label->setDisabled(true);
    ui->expo_label->setDisabled(true);
    ui->brightness_label->setDisabled(true);
    ui->gain_label->setDisabled(true);
    ui->sharpness_label->setDisabled(true);

    ui->redOut_label->setDisabled(true);
    ui->blueOut_label->setDisabled(true);
    ui->expoOut_label->setDisabled(true);
    ui->brightnessOut_label->setDisabled(true);
    ui->gainOut_label->setDisabled(true);
    ui->sharpnessOut_label->setDisabled(true);
}

void MainWindow::enableXML()
{
    ui->xmlAdd_lineEdit->setEnabled(true);
    ui->xml_button->setEnabled(true);
}

void MainWindow::disableXML()
{
    ui->xmlAdd_lineEdit->setDisabled(true);
    ui->xml_button->setDisabled(true);
}

bool MainWindow::isValidPlaceForSelect(int x, int y)
{
    bool isValid = false ;

    if((x > ui->outputLabel->x() && x<(ui->outputLabel->x()+ui->outputLabel->width())))
    {
        if(y>ui->outputLabel->y() && y<ui->outputLabel->y()+ui->outputLabel->height())
        {
            isValid = true;
        }
    }

    return isValid;
}

void MainWindow::openSetting(QString fileAddress)
{
    ColorSettings setting;

    fstream input;
    input.open(fileAddress.toUtf8(), ios::in | ios::binary);
    if (!input)
    {
        qDebug() << fileAddress << ": File not found.  Creating a new file." << endl;

    }
    else if (!setting.ParseFromIstream(&input))
    {
        qDebug() << "Failed";
    }
    else
    {
        ui->blue_slider->setValue(setting.input_white_balance_blue_u());
        ui->blueOut_label->setText(QString::number(setting.input_white_balance_blue_u()));

        ui->red_slider->setValue(setting.input_white_balance_red_v());
        ui->redOut_label->setText(QString::number(setting.input_white_balance_red_v()));

        ui->exposure_slider->setValue(setting.input_exposure());
        ui->expoOut_label->setText(QString::number(setting.input_exposure()));

        ui->brightness_slider->setValue(setting.input_brightness());
        ui->brightnessOut_label->setText(QString::number(setting.input_brightness()));

        ui->sharpness_slider->setValue(setting.input_sharpness());
        ui->sharpnessOut_label->setText(QString::number(setting.input_sharpness()));

        ui->gain_slider->setValue(setting.input_gain());
        ui->gainOut_label->setText(QString::number(setting.input_gain()));

        ui->hue_slider->setValue(setting.input_hue());
        ui->hueOut_label->setText(QString::number(setting.input_hue()));

        ui->saturation_slider->setValue(setting.input_sat());
        ui->saturationOut_label->setText(QString::number(setting.input_sat()));

        ui->contrast_slider->setValue(setting.input_contrast());
        ui->contrastOut_label->setText(QString::number(setting.input_contrast()));

        //Add red Colors
        for(int i=0;i<setting.red_instances_size();i++)
        {
            Vec3f min;
            min.val[0] = setting.red_instances(i).min_hue();
            min.val[1] = setting.red_instances(i).min_sat();
            min.val[2] = setting.red_instances(i).min_val();
            imageProcessor->min_red_samples.push_back(min);

            Vec3f max;
            max.val[0] = setting.red_instances(i).max_hue();
            max.val[1] = setting.red_instances(i).max_sat();
            max.val[2] = setting.red_instances(i).max_val();
            imageProcessor->max_red_samples.push_back(max);
        }
        ui->red_status_label->setText(QString::number(imageProcessor->max_red_samples.size())+" Color at list.");

        //Add blue colors
        for(int i=0;i<setting.blue_instances_size();i++)
        {
            Vec3f min;
            min.val[0] = setting.blue_instances(i).min_hue();
            min.val[1] = setting.blue_instances(i).min_sat();
            min.val[2] = setting.blue_instances(i).min_val();
            imageProcessor->min_blue_samples.push_back(min);

            Vec3f max;
            max.val[0] = setting.blue_instances(i).max_hue();
            max.val[1] = setting.blue_instances(i).max_sat();
            max.val[2] = setting.blue_instances(i).max_val();
            imageProcessor->max_blue_samples.push_back(max);
        }
        ui->blue_status_label->setText(QString::number(imageProcessor->max_blue_samples.size())+" Color at list.");

        //Add green colors
        for(int i=0;i<setting.green_instances_size();i++)
        {
            Vec3f min;
            min.val[0] = setting.green_instances(i).min_hue();
            min.val[1] = setting.green_instances(i).min_sat();
            min.val[2] = setting.green_instances(i).min_val();
            imageProcessor->min_green_samples.push_back(min);

            Vec3f max;
            max.val[0] = setting.green_instances(i).max_hue();
            max.val[1] = setting.green_instances(i).max_sat();
            max.val[2] = setting.green_instances(i).max_val();
            imageProcessor->max_green_samples.push_back(max);
        }
        ui->green_status_label->setText(QString::number(imageProcessor->max_green_samples.size())+" Color at list.");

        //Add yellow colors
        for(int i=0;i<setting.yellow_instances_size();i++)
        {
            Vec3f min;
            min.val[0] = setting.yellow_instances(i).min_hue();
            min.val[1] = setting.yellow_instances(i).min_sat();
            min.val[2] = setting.yellow_instances(i).min_val();
            imageProcessor->min_yellow_samples.push_back(min);

            Vec3f max;
            max.val[0] = setting.yellow_instances(i).max_hue();
            max.val[1] = setting.yellow_instances(i).max_sat();
            max.val[2] = setting.yellow_instances(i).max_val();
            imageProcessor->max_yellow_samples.push_back(max);
        }
        ui->yellow_status_label->setText(QString::number(imageProcessor->max_yellow_samples.size())+" Color at list.");

        //Add violet colors
        for(int i=0;i<setting.violet_instances_size();i++)
        {
            Vec3f min;
            min.val[0] = setting.violet_instances(i).min_hue();
            min.val[1] = setting.violet_instances(i).min_sat();
            min.val[2] = setting.violet_instances(i).min_val();
            imageProcessor->min_violet_samples.push_back(min);

            Vec3f max;
            max.val[0] = setting.violet_instances(i).max_hue();
            max.val[1] = setting.violet_instances(i).max_sat();
            max.val[2] = setting.violet_instances(i).max_val();
            imageProcessor->max_violet_samples.push_back(max);
        }
        ui->violet_status_label->setText(QString::number(imageProcessor->max_violet_samples.size())+" Color at list.");

        //Add cyan colors
        for(int i=0;i<setting.cyan_instances_size();i++)
        {
            Vec3f min;
            min.val[0] = setting.cyan_instances(i).min_hue();
            min.val[1] = setting.cyan_instances(i).min_sat();
            min.val[2] = setting.cyan_instances(i).min_val();
            imageProcessor->min_cyan_samples.push_back(min);

            Vec3f max;
            max.val[0] = setting.cyan_instances(i).max_hue();
            max.val[1] = setting.cyan_instances(i).max_sat();
            max.val[2] = setting.cyan_instances(i).max_val();
            imageProcessor->max_cyan_samples.push_back(max);
        }
        ui->cyan_status_label->setText(QString::number(imageProcessor->max_cyan_samples.size())+" Color at list.");

        //Add black colors
        for(int i=0;i<setting.black_instances_size();i++)
        {
            Vec3f min;
            min.val[0] = setting.black_instances(i).min_hue();
            min.val[1] = setting.black_instances(i).min_sat();
            min.val[2] = setting.black_instances(i).min_val();
            imageProcessor->min_black_samples.push_back(min);

            Vec3f max;
            max.val[0] = setting.black_instances(i).max_hue();
            max.val[1] = setting.black_instances(i).max_sat();
            max.val[2] = setting.black_instances(i).max_val();
            imageProcessor->max_black_samples.push_back(max);
        }
        ui->black_status_label->setText(QString::number(imageProcessor->max_black_samples.size())+" Color at list.");
    }
}

void MainWindow::callImageProcessingFunctions(Mat input_mat)
{
    //undisort image
    Mat inputFrame;

    imageProcessor->undistortImage(input_mat).copyTo(inputFrame);

    semaphoreForColorImage->acquire(1);
    frameForColorDetection = inputFrame;
    semaphoreForColorImage->release(1);

    semaphore->acquire();
    imProcDataAvailable=false;
    Mat outputFrame;
    inputFrame.copyTo(outputFrame);
    imProcDataAvailable=true;
    semaphore->release();

    if(!outputFrame.empty())
    {
        cv::resize(outputFrame,outputFrame,Size(640,480),0,0,INTER_CUBIC);
        QImage imgIn;

        cvtColor(outputFrame, outputFrame, COLOR_BGR2RGB);

        imgIn= QImage((uchar*) outputFrame.data, outputFrame.cols, outputFrame.rows, outputFrame.step, QImage::Format_RGB888);
        ui->outputLabel->setPixmap(QPixmap::fromImage(imgIn));
    }
}

void MainWindow::on_camSet_checkBox_stateChanged()
{
    if(ui->camSet_checkBox->isChecked())
    {
        enableCameraSetting();
    }
    else
    {
        disableCameraSetting();
    }
}

void MainWindow::on_xml_checkBox_stateChanged()
{
    if(ui->xml_checkBox->isChecked())
    {
        enableXML();
    }
    else
    {
        disableXML();
    }
}

void MainWindow::on_xml_button_clicked()
{
    QString fileAddress = QFileDialog::getOpenFileName(this,tr("Select Your XML File"), "/home", tr("XML Files (*.xml)"));
    ui->xmlAdd_lineEdit->setText(fileAddress);
    QFile inputXMLFile(fileAddress);
    QXmlStreamReader cameraXMLSetting(&inputXMLFile);

    while (!cameraXMLSetting.atEnd() && !cameraXMLSetting.hasError())
    {
        qDebug()<<"reading xml file";
        cameraXMLSetting.readNext();
        if (cameraXMLSetting.isStartElement())
        {

        }
        else if (cameraXMLSetting.hasError())
        {
            qDebug() << "XML error: " << cameraXMLSetting.errorString() << endl;
        }
        else if (cameraXMLSetting.atEnd())
        {
            qDebug() << "Reached end, done" << endl;
        }
    }
}

void MainWindow::on_blue_slider_sliderMoved(int position)
{
    ui->blueOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}

void MainWindow::on_red_slider_sliderMoved(int position)
{
    ui->redOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}

void MainWindow::on_exposure_slider_sliderMoved(int position)
{
    ui->expoOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}

void MainWindow::on_brightness_slider_sliderMoved(int position)
{
    ui->brightnessOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}

void MainWindow::updateCameraSetting()
{
    setCameraSetting();
}

void MainWindow::setCameraSetting()
{
    if(cameraIsOpened)
    {
        cap.set(CAP_PROP_FPS, ui->fps_comboBox->currentText().toInt());
        camSetting->set_fps(ui->fps_comboBox->currentText().toInt());

        cap.set(CAP_PROP_WHITE_BALANCE_BLUE_U,ui->blue_slider->value());
        camSetting->set_WHITE_BALANCE_BLUE_U(ui->blue_slider->value());

        cap.set(CAP_PROP_WHITE_BALANCE_RED_V,ui->red_slider->value());
        camSetting->set_WHITE_BALANCE_RED_V(ui->red_slider->value());

        cap.set(CAP_PROP_BRIGHTNESS,ui->brightness_slider->value());
        camSetting->set_BRIGHTNESS(ui->brightness_slider->value());

        cap.set(CAP_PROP_EXPOSURE,ui->exposure_slider->value());
        camSetting->set_EXPOSURE(ui->exposure_slider->value());

        cap.set(CAP_PROP_SHARPNESS,ui->sharpness_slider->value());
        camSetting->set_SHARPNESS(ui->sharpness_slider->value());

        cap.set(CAP_PROP_GAIN,ui->gain_slider->value());
        camSetting->set_GAIN(ui->gain_slider->value());

        cap.set(CAP_PROP_HUE,ui->hue_slider->value());
        camSetting->set_HUE(ui->hue_slider->value());

        cap.set(CAP_PROP_SATURATION,ui->saturation_slider->value());
        camSetting->set_SATURATION(ui->saturation_slider->value());

        cap.set(CAP_PROP_CONTRAST,ui->contrast_slider->value());
        camSetting->set_CONTRAST(ui->contrast_slider->value());
    }
}

void MainWindow::on_sharpness_slider_sliderMoved(int position)
{
    ui->sharpnessOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}

void MainWindow::on_gain_slider_sliderMoved(int position)
{
    ui->gainOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseMove || event->type() == QEvent::MouseButtonRelease)
    {
        if(colorMode || mouseButtonClicked)
        {
            return QMainWindow::eventFilter(obj, event);
        }
        else
        {
            qDebug()<<"Select a mode!";
        }
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(isValidPlaceForSelect(event->x(),event->y()))
    {
        origin = event->pos();
        rubberBand->setGeometry(QRect(origin, QSize()));
        rubberBand->show();
        firstPointSelectedIsValid = true;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(isValidPlaceForSelect(event->x(),event->y()))
    {
        rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
    }
    else
    {
        rubberBand->hide();
        firstPointSelectedIsValid = false;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(isValidPlaceForSelect(event->x(),event->y()))
    {
        if(firstPointSelectedIsValid)
        {
            if(colorMode)
            {
                semaphoreForColorImage->acquire(1);
                cam_timer->stop();

                Rect cropedRect;
                cropedRect.width = event->x()-origin.x();
                cropedRect.height = event->y()-origin.y();
                cropedRect.x = origin.x()-ui->outputLabel->x();
                cropedRect.y = origin.y()-ui->outputLabel->y();

                Mat CropFrame(frameForColorDetection,cropedRect);
                //imageProcessor->returnHsv(CropFrame);
                vector<Vec3f> range = imageProcessor->returnColor(CropFrame,frameForColorDetection);

                Vec3f min = range.at(0);
                Vec3f max = range.at(1);

                if(whichColor == "red")
                {
                    ui->red_min_hue_lineEdit->setText(QString::number((int)min.val[0]));
                    ui->red_min_sat_lineEdit->setText(QString::number((int)min.val[1]));
                    ui->red_min_value_lineEdit->setText(QString::number((int)min.val[2]));

                    ui->red_max_hue_lineEdit->setText(QString::number((int)max.val[0]));
                    ui->red_max_sat_lineEdit->setText(QString::number((int)max.val[1]));
                    ui->red_max_value_lineEdit->setText(QString::number((int)max.val[2]));
                }
                else if(whichColor == "blue")
                {
                    ui->blue_min_hue_lineEdit->setText(QString::number((int)min.val[0]));
                    ui->blue_min_sat_lineEdit->setText(QString::number((int)min.val[1]));
                    ui->blue_min_value_lineEdit->setText(QString::number((int)min.val[2]));

                    ui->blue_max_hue_lineEdit->setText(QString::number((int)max.val[0]));
                    ui->blue_max_sat_lineEdit->setText(QString::number((int)max.val[1]));
                    ui->blue_max_value_lineEdit->setText(QString::number((int)max.val[2]));
                }
                else if(whichColor == "green")
                {
                    ui->green_min_hue_lineEdit->setText(QString::number((int)min.val[0]));
                    ui->green_min_sat_lineEdit->setText(QString::number((int)min.val[1]));
                    ui->green_min_value_lineEdit->setText(QString::number((int)min.val[2]));

                    ui->green_max_hue_lineEdit->setText(QString::number((int)max.val[0]));
                    ui->green_max_sat_lineEdit->setText(QString::number((int)max.val[1]));
                    ui->green_max_value_lineEdit->setText(QString::number((int)max.val[2]));
                }
                else if(whichColor == "yellow")
                {
                    ui->yellow_min_hue_lineEdit->setText(QString::number((int)min.val[0]));
                    ui->yellow_min_sat_lineEdit->setText(QString::number((int)min.val[1]));
                    ui->yellow_min_value_lineEdit->setText(QString::number((int)min.val[2]));

                    ui->yellow_max_hue_lineEdit->setText(QString::number((int)max.val[0]));
                    ui->yellow_max_sat_lineEdit->setText(QString::number((int)max.val[1]));
                    ui->yellow_max_value_lineEdit->setText(QString::number((int)max.val[2]));
                }
                else if(whichColor == "cyan")
                {
                    ui->cyan_min_hue_lineEdit->setText(QString::number((int)min.val[0]));
                    ui->cyan_min_sat_lineEdit->setText(QString::number((int)min.val[1]));
                    ui->cyan_min_value_lineEdit->setText(QString::number((int)min.val[2]));

                    ui->cyan_max_hue_lineEdit->setText(QString::number((int)max.val[0]));
                    ui->cyan_max_sat_lineEdit->setText(QString::number((int)max.val[1]));
                    ui->cyan_max_value_lineEdit->setText(QString::number((int)max.val[2]));
                }
                else if(whichColor == "violet")
                {
                    ui->violet_min_hue_lineEdit->setText(QString::number((int)min.val[0]));
                    ui->violet_min_sat_lineEdit->setText(QString::number((int)min.val[1]));
                    ui->violet_min_value_lineEdit->setText(QString::number((int)min.val[2]));

                    ui->violet_max_hue_lineEdit->setText(QString::number((int)max.val[0]));
                    ui->violet_max_sat_lineEdit->setText(QString::number((int)max.val[1]));
                    ui->violet_max_value_lineEdit->setText(QString::number((int)max.val[2]));
                }
                else if(whichColor == "black")
                {
                    ui->black_min_hue_lineEdit->setText(QString::number((int)min.val[0]));
                    ui->black_min_sat_lineEdit->setText(QString::number((int)min.val[1]));
                    ui->black_min_value_lineEdit->setText(QString::number((int)min.val[2]));

                    ui->black_max_hue_lineEdit->setText(QString::number((int)max.val[0]));
                    ui->black_max_sat_lineEdit->setText(QString::number((int)max.val[1]));
                    ui->black_max_value_lineEdit->setText(QString::number((int)max.val[2]));
                }

                cam_timer->start();
                semaphoreForColorImage->release(1);

            }
        }
    }

    rubberBand->hide();
    firstPointSelectedIsValid = false;
}

void MainWindow::on_redSelect_button_clicked()
{
    whichColor = "red";
    colorMode = true;
    QApplication::setOverrideCursor(Qt::CrossCursor);
}

void MainWindow::on_blueSelect_button_clicked()
{
    whichColor = "blue";
    colorMode = true;
    QApplication::setOverrideCursor(Qt::CrossCursor);
}

void MainWindow::on_greenSelect_button_clicked()
{
    whichColor = "green";
    colorMode = true;
    QApplication::setOverrideCursor(Qt::CrossCursor);
}

void MainWindow::on_yellowSelect_button_clicked()
{
    whichColor = "yellow";
    colorMode = true;
    QApplication::setOverrideCursor(Qt::CrossCursor);
}

void MainWindow::on_violetSelect_button_clicked()
{
    whichColor = "violet";
    colorMode = true;
    QApplication::setOverrideCursor(Qt::CrossCursor);
}

void MainWindow::on_cyanSelect_button_clicked()
{
    whichColor = "cyan";
    colorMode = true;
    QApplication::setOverrideCursor(Qt::CrossCursor);
}

void MainWindow::on_blackSelect_button_clicked()
{
    whichColor = "black";
    colorMode = true;
    QApplication::setOverrideCursor(Qt::CrossCursor);
}

void MainWindow::on_save_set_button_clicked()
{
    disconnect(cam_timer,SIGNAL(timeout()),this,SLOT(cam_timeout()));

    ColorSettings setting;

    setting.set_input_white_balance_blue_u(ui->blue_slider->value());
    setting.set_input_white_balance_red_v(ui->red_slider->value());
    setting.set_input_exposure(ui->exposure_slider->value());
    setting.set_input_brightness(ui->brightness_slider->value());
    setting.set_input_sharpness(ui->sharpness_slider->value());
    setting.set_input_gain(ui->gain_slider->value());
    setting.set_input_hue(ui->hue_slider->value());
    setting.set_input_sat(ui->saturation_slider->value());
    setting.set_input_contrast(ui->contrast_slider->value());

    //Add Colors!
    if(imageProcessor->min_red_samples.size() >0)
    {
        for(int i=0;i<imageProcessor->min_red_samples.size();i++)
        {
            ColorSettings_color *color = setting.add_red_instances();

            color->set_min_hue(imageProcessor->min_red_samples.at(i).val[0]);
            color->set_min_sat(imageProcessor->min_red_samples.at(i).val[1]);
            color->set_min_val(imageProcessor->min_red_samples.at(i).val[2]);

            color->set_max_hue(imageProcessor->max_red_samples.at(i).val[0]);
            color->set_max_sat(imageProcessor->max_red_samples.at(i).val[1]);
            color->set_max_val(imageProcessor->max_red_samples.at(i).val[2]);
        }
    }

    if(imageProcessor->min_blue_samples.size() >0)
    {
        for(int i=0;i<imageProcessor->min_blue_samples.size();i++)
        {
            ColorSettings_color *color = setting.add_blue_instances();

            color->set_min_hue(imageProcessor->min_blue_samples.at(i).val[0]);
            color->set_min_sat(imageProcessor->min_blue_samples.at(i).val[1]);
            color->set_min_val(imageProcessor->min_blue_samples.at(i).val[2]);

            color->set_max_hue(imageProcessor->max_blue_samples.at(i).val[0]);
            color->set_max_sat(imageProcessor->max_blue_samples.at(i).val[1]);
            color->set_max_val(imageProcessor->max_blue_samples.at(i).val[2]);
        }
    }

    if(imageProcessor->min_green_samples.size() >0)
    {
        for(int i=0;i<imageProcessor->min_green_samples.size();i++)
        {
            ColorSettings_color *color = setting.add_green_instances();

            color->set_min_hue(imageProcessor->min_green_samples.at(i).val[0]);
            color->set_min_sat(imageProcessor->min_green_samples.at(i).val[1]);
            color->set_min_val(imageProcessor->min_green_samples.at(i).val[2]);

            color->set_max_hue(imageProcessor->max_green_samples.at(i).val[0]);
            color->set_max_sat(imageProcessor->max_green_samples.at(i).val[1]);
            color->set_max_val(imageProcessor->max_green_samples.at(i).val[2]);
        }
    }

    if(imageProcessor->min_yellow_samples.size() >0)
    {
        for(int i=0;i<imageProcessor->min_yellow_samples.size();i++)
        {
            ColorSettings_color *color = setting.add_yellow_instances();

            color->set_min_hue(imageProcessor->min_yellow_samples.at(i).val[0]);
            color->set_min_sat(imageProcessor->min_yellow_samples.at(i).val[1]);
            color->set_min_val(imageProcessor->min_yellow_samples.at(i).val[2]);

            color->set_max_hue(imageProcessor->max_yellow_samples.at(i).val[0]);
            color->set_max_sat(imageProcessor->max_yellow_samples.at(i).val[1]);
            color->set_max_val(imageProcessor->max_yellow_samples.at(i).val[2]);
        }
    }

    if(imageProcessor->min_violet_samples.size() >0)
    {
        for(int i=0;i<imageProcessor->min_violet_samples.size();i++)
        {
            ColorSettings_color *color = setting.add_violet_instances();

            color->set_min_hue(imageProcessor->min_violet_samples.at(i).val[0]);
            color->set_min_sat(imageProcessor->min_violet_samples.at(i).val[1]);
            color->set_min_val(imageProcessor->min_violet_samples.at(i).val[2]);

            color->set_max_hue(imageProcessor->max_violet_samples.at(i).val[0]);
            color->set_max_sat(imageProcessor->max_violet_samples.at(i).val[1]);
            color->set_max_val(imageProcessor->max_violet_samples.at(i).val[2]);
        }
    }

    if(imageProcessor->min_cyan_samples.size() >0)
    {
        for(int i=0;i<imageProcessor->min_cyan_samples.size();i++)
        {
            ColorSettings_color *color = setting.add_cyan_instances();

            color->set_min_hue(imageProcessor->min_cyan_samples.at(i).val[0]);
            color->set_min_sat(imageProcessor->min_cyan_samples.at(i).val[1]);
            color->set_min_val(imageProcessor->min_cyan_samples.at(i).val[2]);

            color->set_max_hue(imageProcessor->max_cyan_samples.at(i).val[0]);
            color->set_max_sat(imageProcessor->max_cyan_samples.at(i).val[1]);
            color->set_max_val(imageProcessor->max_cyan_samples.at(i).val[2]);
        }
    }

    if(imageProcessor->min_black_samples.size() >0)
    {
        for(int i=0;i<imageProcessor->min_black_samples.size();i++)
        {
            ColorSettings_color *color = setting.add_black_instances();

            color->set_min_hue(imageProcessor->min_black_samples.at(i).val[0]);
            color->set_min_sat(imageProcessor->min_black_samples.at(i).val[1]);
            color->set_min_val(imageProcessor->min_black_samples.at(i).val[2]);

            color->set_max_hue(imageProcessor->max_black_samples.at(i).val[0]);
            color->set_max_sat(imageProcessor->max_black_samples.at(i).val[1]);
            color->set_max_val(imageProcessor->max_black_samples.at(i).val[2]);
        }
    }

    QString fileAddress = QFileDialog::getSaveFileName(this,tr("Select Directory..."), "/home", tr("Text File (*.txt)"));
    QFile file(fileAddress);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text ))
    {
        qDebug() << "File Has Been Created" << endl;
        fstream output;
        output.open(fileAddress.toUtf8(), fstream::out | fstream::trunc | fstream::binary);;
        if (!setting.SerializeToOstream(&output)) {
            qDebug() << "Failed to write data." << endl;
            //file.close();
        }
    }
    else
    {
        qDebug() << "Failed to Create File" << endl;
    }

    connect(cam_timer,SIGNAL(timeout()),this,SLOT(cam_timeout()));
}

void MainWindow::on_open_set_button_clicked()
{
    disconnect(cam_timer,SIGNAL(timeout()),this,SLOT(cam_timeout()));

    QString fileAddress = QFileDialog::getOpenFileName(this,tr("Select Setting File"), "/home", tr("Text File (*.txt)"));

    openSetting(fileAddress);

    connect(cam_timer,SIGNAL(timeout()),this,SLOT(cam_timeout()));
}

void MainWindow::on_add_red_button_clicked()
{
    Vec3f min;
    min.val[0] = ui->red_min_hue_lineEdit->text().toFloat();
    min.val[1] = ui->red_min_sat_lineEdit->text().toFloat();
    min.val[2] = ui->red_min_value_lineEdit->text().toFloat();
    imageProcessor->min_red_samples.push_back(min);

    Vec3f max;
    max.val[0] = ui->red_max_hue_lineEdit->text().toFloat();
    max.val[1] = ui->red_max_sat_lineEdit->text().toFloat();
    max.val[2] = ui->red_max_value_lineEdit->text().toFloat();
    imageProcessor->max_red_samples.push_back(max);

    QString status;
    status = QString::number(imageProcessor->max_red_samples.size()) + " Color at list.";
    ui->red_status_label->setText(status);
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    colorMode = false;
}

void MainWindow::on_add_blue_button_clicked()
{
    Vec3f min;
    min.val[0] = ui->blue_min_hue_lineEdit->text().toFloat();
    min.val[1] = ui->blue_min_sat_lineEdit->text().toFloat();
    min.val[2] = ui->blue_min_value_lineEdit->text().toFloat();
    imageProcessor->min_blue_samples.push_back(min);

    Vec3f max;
    max.val[0] = ui->blue_max_hue_lineEdit->text().toFloat();
    max.val[1] = ui->blue_max_sat_lineEdit->text().toFloat();
    max.val[2] = ui->blue_max_value_lineEdit->text().toFloat();
    imageProcessor->max_blue_samples.push_back(max);

    QString status;
    status = QString::number(imageProcessor->max_blue_samples.size()) + " Color at list.";
    ui->blue_status_label->setText(status);
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    colorMode = false;
}

void MainWindow::on_add_green_button_clicked()
{
    Vec3f min;
    min.val[0] = ui->green_min_hue_lineEdit->text().toFloat();
    min.val[1] = ui->green_min_sat_lineEdit->text().toFloat();
    min.val[2] = ui->green_min_value_lineEdit->text().toFloat();
    imageProcessor->min_green_samples.push_back(min);

    Vec3f max;
    max.val[0] = ui->green_max_hue_lineEdit->text().toFloat();
    max.val[1] = ui->green_max_sat_lineEdit->text().toFloat();
    max.val[2] = ui->green_max_value_lineEdit->text().toFloat();
    imageProcessor->max_green_samples.push_back(max);

    QString status;
    status = QString::number(imageProcessor->max_green_samples.size()) + " Color at list.";
    ui->green_status_label->setText(status);
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    colorMode = false;
}

void MainWindow::on_add_yellow_button_clicked()
{
    Vec3f min;
    min.val[0] = ui->yellow_min_hue_lineEdit->text().toFloat();
    min.val[1] = ui->yellow_min_sat_lineEdit->text().toFloat();
    min.val[2] = ui->yellow_min_value_lineEdit->text().toFloat();
    imageProcessor->min_yellow_samples.push_back(min);

    Vec3f max;
    max.val[0] = ui->yellow_max_hue_lineEdit->text().toFloat();
    max.val[1] = ui->yellow_max_sat_lineEdit->text().toFloat();
    max.val[2] = ui->yellow_max_value_lineEdit->text().toFloat();
    imageProcessor->max_yellow_samples.push_back(max);

    QString status;
    status = QString::number(imageProcessor->max_yellow_samples.size()) + " Color at list.";
    ui->yellow_status_label->setText(status);
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    colorMode = false;
}

void MainWindow::on_add_violet_button_clicked()
{
    Vec3f min;
    min.val[0] = ui->violet_min_hue_lineEdit->text().toFloat();
    min.val[1] = ui->violet_min_sat_lineEdit->text().toFloat();
    min.val[2] = ui->violet_min_value_lineEdit->text().toFloat();
    imageProcessor->min_violet_samples.push_back(min);

    Vec3f max;
    max.val[0] = ui->violet_max_hue_lineEdit->text().toFloat();
    max.val[1] = ui->violet_max_sat_lineEdit->text().toFloat();
    max.val[2] = ui->violet_max_value_lineEdit->text().toFloat();
    imageProcessor->max_violet_samples.push_back(max);

    QString status;
    status = QString::number(imageProcessor->max_violet_samples.size()) + " Color at list.";
    ui->violet_status_label->setText(status);
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    colorMode = false;
}

void MainWindow::on_add_cyan_button_clicked()
{
    Vec3f min;
    min.val[0] = ui->cyan_min_hue_lineEdit->text().toFloat();
    min.val[1] = ui->cyan_min_sat_lineEdit->text().toFloat();
    min.val[2] = ui->cyan_min_value_lineEdit->text().toFloat();
    imageProcessor->min_cyan_samples.push_back(min);

    Vec3f max;
    max.val[0] = ui->cyan_max_hue_lineEdit->text().toFloat();
    max.val[1] = ui->cyan_max_sat_lineEdit->text().toFloat();
    max.val[2] = ui->cyan_max_value_lineEdit->text().toFloat();
    imageProcessor->max_cyan_samples.push_back(max);

    QString status;
    status = QString::number(imageProcessor->max_cyan_samples.size()) + " Color at list.";
    ui->cyan_status_label->setText(status);
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    colorMode = false;
}

void MainWindow::on_add_black_button_clicked()
{
    Vec3f min;
    min.val[0] = ui->black_min_hue_lineEdit->text().toFloat();
    min.val[1] = ui->black_min_sat_lineEdit->text().toFloat();
    min.val[2] = ui->black_min_value_lineEdit->text().toFloat();
    imageProcessor->min_black_samples.push_back(min);

    Vec3f max;
    max.val[0] = ui->black_max_hue_lineEdit->text().toFloat();
    max.val[1] = ui->black_max_sat_lineEdit->text().toFloat();
    max.val[2] = ui->black_max_value_lineEdit->text().toFloat();
    imageProcessor->max_black_samples.push_back(max);

    QString status;
    status = QString::number(imageProcessor->max_black_samples.size()) + " Color at list.";
    ui->black_status_label->setText(status);
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    colorMode = false;
}

void MainWindow::on_cancel_button_clicked()
{
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    colorMode = false;
}

void MainWindow::on_clear_red_button_clicked()
{
    imageProcessor->min_red_samples.clear();
    imageProcessor->max_red_samples.clear();
    ui->red_status_label->setText(QString::number(imageProcessor->min_red_samples.size()) + " Color at list.");

    ui->red_min_hue_lineEdit->clear();
    ui->red_min_sat_lineEdit->clear();
    ui->red_min_value_lineEdit->clear();
    ui->red_max_hue_lineEdit->clear();
    ui->red_max_sat_lineEdit->clear();
    ui->red_max_value_lineEdit->clear();
}

void MainWindow::on_clear_blue_button_clicked()
{
    imageProcessor->min_blue_samples.clear();
    imageProcessor->max_blue_samples.clear();
    ui->blue_status_label->setText(QString::number(imageProcessor->min_blue_samples.size()) + " Color at list.");

    ui->blue_min_hue_lineEdit->clear();
    ui->blue_min_sat_lineEdit->clear();
    ui->blue_min_value_lineEdit->clear();
    ui->blue_max_hue_lineEdit->clear();
    ui->blue_max_sat_lineEdit->clear();
    ui->blue_max_value_lineEdit->clear();
}

void MainWindow::on_clear_green_button_clicked()
{
    imageProcessor->min_green_samples.clear();
    imageProcessor->max_green_samples.clear();
    ui->green_status_label->setText(QString::number(imageProcessor->min_green_samples.size()) + " Color at list.");

    ui->green_min_hue_lineEdit->clear();
    ui->green_min_sat_lineEdit->clear();
    ui->green_min_value_lineEdit->clear();
    ui->green_max_hue_lineEdit->clear();
    ui->green_max_sat_lineEdit->clear();
    ui->green_max_value_lineEdit->clear();
}

void MainWindow::on_clear_yellow_button_clicked()
{
    imageProcessor->min_yellow_samples.clear();
    imageProcessor->max_yellow_samples.clear();
    ui->yellow_status_label->setText(QString::number(imageProcessor->min_yellow_samples.size()) + " Color at list.");

    ui->yellow_min_hue_lineEdit->clear();
    ui->yellow_min_sat_lineEdit->clear();
    ui->yellow_min_value_lineEdit->clear();
    ui->yellow_max_hue_lineEdit->clear();
    ui->yellow_max_sat_lineEdit->clear();
    ui->yellow_max_value_lineEdit->clear();
}

void MainWindow::on_clear_violet_button_clicked()
{
    imageProcessor->min_violet_samples.clear();
    imageProcessor->max_violet_samples.clear();
    ui->violet_status_label->setText(QString::number(imageProcessor->min_violet_samples.size()) + " Color at list.");

    ui->violet_min_hue_lineEdit->clear();
    ui->violet_min_sat_lineEdit->clear();
    ui->violet_min_value_lineEdit->clear();
    ui->violet_max_hue_lineEdit->clear();
    ui->violet_max_sat_lineEdit->clear();
    ui->violet_max_value_lineEdit->clear();
}

void MainWindow::on_clear_cyan_button_clicked()
{
    imageProcessor->min_cyan_samples.clear();
    imageProcessor->max_cyan_samples.clear();
    ui->cyan_status_label->setText(QString::number(imageProcessor->min_cyan_samples.size()) + " Color at list.");

    ui->cyan_min_hue_lineEdit->clear();
    ui->cyan_min_sat_lineEdit->clear();
    ui->cyan_min_value_lineEdit->clear();
    ui->cyan_max_hue_lineEdit->clear();
    ui->cyan_max_sat_lineEdit->clear();
    ui->cyan_max_value_lineEdit->clear();
}

void MainWindow::on_clear_black_button_clicked()
{
    imageProcessor->min_black_samples.clear();
    imageProcessor->max_black_samples.clear();
    ui->black_status_label->setText(QString::number(imageProcessor->min_black_samples.size()) + " Color at list.");

    ui->black_min_hue_lineEdit->clear();
    ui->black_min_sat_lineEdit->clear();
    ui->black_min_value_lineEdit->clear();
    ui->black_max_hue_lineEdit->clear();
    ui->black_max_sat_lineEdit->clear();
    ui->black_max_value_lineEdit->clear();
}

void MainWindow::on_hue_slider_sliderMoved(int position)
{
    ui->hueOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}

void MainWindow::on_saturation_slider_sliderMoved(int position)
{
    ui->saturationOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}

void MainWindow::on_contrast_slider_sliderMoved(int position)
{
    ui->contrastOut_label->setText(QString::number(position));
    emit cameraSettingChanged();
}
