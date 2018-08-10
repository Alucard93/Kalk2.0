#include <colorfactory.h>
Color* ColorFactory::GetNewColor(QString type, QVector<double> values){
    if(type=="cie_xyz")
        return new CIExyz(values[0],values[1],values[2]);
    else if(type=="rgb")
        return new RGB(values[0],values[1],values[2]);
    else if(type=="cymk")
        return new CYMK(values[0],values[1],values[2],values[3]);
    else if(type=="hsl")
        return new HSL(values[0],values[1],values[2]);
    else if(type=="ycbcr")
        return new YCbCr();
    else if(type=="yuv")
        return new YUV();
}

QVector<QString>ColorFactory::GetTypes(){
    QVector<QString> data;
    data.push_back("cie_xyz");
    data.push_back("rgb");
    data.push_back("cymk");
    data.push_back("hsl");
    data.push_back("ycbcr");
    data.push_back("yuv");
    return data;
}
