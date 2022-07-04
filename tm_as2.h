#pragma once

#include <opencv2/core/types.hpp>

namespace as
{
    enum OptionArrangement
    {
        OPTIONMATRIX_HORIZONTAL = 0,
        OPTIONMATRIX_VERTICAL = 1
    };

    enum MCQ 
    { 
        SINGLE_ANSWER = 1, 
        MULTIPLE_ANSWERS = 2
    };

    enum AreaType
    {
        OPTIONMATRIX = 10,
        BARCODE = 11,
        QRCODE = 12
    };

    enum Axis
    {
        X = 0,
        Y = 1
    };

    enum Color
    {
        BLACK = 0,
        WHITE = 255
    };

    enum BinarizationMethods 
    {
        OTSU = 0,
        ADAPTIVE = 1,
        SAUVOLA = 2
    };

    enum Rotate 
    {
        CROPPING = 0,
        WITHOUT_CROPPING = 1
    };

    enum Thickness 
    {
        VERY_THIN = 0,
        THIN = 1,
        MEDIUM = 2,
        THICK = 3,
        VERY_THICK = 4
    };

    enum ErrorCode
    {
        UNKNOWN_EXCEPTION = -101,
        EXCEPTION = -102,
        TM_EXCEPTION = -103,
        CV_EXCEPTION = -104
    };

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    const int ATN_OPTIONS_CNT = 10; // 0 ~ 9
    //
    const int ROTATION_CORRECTION_DEGREE = 5;
    //
    const int HOUGH_DISTANCE_RESOLUTION = 1; //生成极坐标的像素扫描步长
    const double HOUGH_ANGLE_RESOLUTION = CV_PI / 180.0 / 10.0; //生成极坐标的角度步长，一般是π/180
    const double HOUGH_VOTE_THRESHOLD_RATIO = 1 / 10.0; //要”检测” 一条直线所需最少的的曲线交点
    const double HOUGH_MIN_LINE_LENGTH_RATIO = 1 / 6.0; //表示最低线段的长度，比这个设定参数短的线段就不能被显现出来。
    const double HOUGH_MAX_LINE_GAP_RATIO = 1 / 500.0; //允许将同一行点与点之间连接起来的最大的距离
    //
    const int MAX_SIMILARITY_OF_RECTS = 100;
    //
    const int BLACK_PIXEL_RATIO_OF_PRINTED_BLACK_BLOCK = 60; // <lc>magic!</lc>
    const int BLACK_PIXEL_RATIO_OF_HAND_FILLED_BLACK_BLOCK = 50; // <lc>magic!</lc> 未填涂在10~22 填涂在50~90
    const int MAX_BLACK_PIXEL_RATIO_OF_OPTION = 100; // 
    const int MIN_BLACK_PIXEL_RATIO_OF_OPTION = 0; // 
    const double COEFFICIENT_OF_VARIATION_FOR_ALL_UNFILLED = 0.15; // <lc>magic!<lc> 变异系数低于此的认为整体填涂区域均未填涂或均填涂
    //
    const int LOCATION_MARKS_CNT = 4; // lt rt ld rd
    const double LOCATION_MARKS_X_RANGE = 0.1; //<lc>magic!<lc>
    const double LOCATION_MARKS_X2_RANGE = 0.2; //<lc>magic!<lc>
    const double LOCATION_MARKS_Y_RANGE = 0.2; //<lc>magic!<lc>
    //
    const int EFFECTIVE_SCORE = 90; //<lc>magic!<lc>
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    const std::string FILE_EXTENTION_TC = ".tc.png";

    //
    const std::string JSON_KEY_PAGEPATH2    = "pagesPaths";
    const std::string JSON_KEY_PAGES2       = "pages";
    const std::string JSON_KEY_ATN2         = "admissionTicketNumber";
    const std::string JSON_KEY_MM2          = "absentMark"; 
    const std::string JSON_KEY_MCQ2         = "multipleChoiceQuestions";
    const std::string JSON_KEY_USR_AT       = "usrAnswerType";
    const std::string JSON_KEY_USR_ROI      = "usrRoi";
    const std::string JSON_KEY_USR_QNS      = "usrQns";
    const std::string JSON_KEY_OM_ROI       = "omRoi";
    const std::string JSON_KEY_OM_OPTIONS   = "omOptions";
    const std::string JSON_KEY_OM_SPACING   = "omSpacing";
    const std::string JSON_KEY_OM_SIZE      = "omSize";
    //
    const std::string JSON_KEY_PAGEPATH     = "PAGEPATH#";
    const std::string JSON_KEY_PAGES        = "PAGES#";
    const std::string JSON_KEY_TC           = "@TC#";
    const std::string JSON_KEY_ATN          = "@ATN#";
    const std::string JSON_KEY_MM           = "@MM#";
    const std::string JSON_KEY_MCQ          = "@MCQ#";
    const std::string JSON_KEY_MCQ_SA       = "@MCQ#SA#";
    const std::string JSON_KEY_MCQ_MA       = "@MCQ#MA#";
    const std::string JSON_KEY_SA           = "SA#";
    const std::string JSON_KEY_MA           = "MA#";
    const std::string JSON_KEY_SCORING_AREA = "scoringArea";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    class FileNameMgr
    {
    public:
        static std::string tc_filename(std::string path)
        {
            auto dir = std::filesystem::path(path);
            auto filename = std::filesystem::path(path).filename();
            
            return (dir / path).string() + FILE_EXTENTION_TC;
        }
        static std::string file_core(std::string fn) // tm_basic.h -> basic
        {
            auto begin = fn.find("_");
            auto end = fn.rfind(".");
            auto core = fn.substr(begin, end - begin);
            return core;
        }
    };

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    const std::string MODELS_DIR = "./models";
    const std::string KNN_MODEL_FILENAME = "cv_ocr_model_115.param";
    const std::string OCR_IMG_PATH = MODELS_DIR + "/ocr.png";

    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
}