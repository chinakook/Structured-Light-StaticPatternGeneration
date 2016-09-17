PM0 = imread('Phase_h/PhaseMat0.bmp');
PM1 = imread('Phase_h/PhaseMat1.bmp');
PM2 = imread('Phase_h/PhaseMat2.bmp');

SinValue = ( double(PM0) * 2 - double(PM1) - double(PM2) ) / 3;
CosValue = ( double(PM1) - double(PM2) ) / sqrt(3);

Res = atan2(SinValue, CosValue);
Min = min(min(Res));
Max = max(max(Res));
Show = (Res - Min)/(Max - Min) * 255;

imshow(uint8(Show));
imwrite(Res, 'Phase_hRes.bmp');
imwrite(Show, 'Phase_hShow.bmp');