#ifndef EASYPR_PLATE_HPP
#define EASYPR_PLATE_HPP

namespace easypr {

namespace demo {

using namespace cv;
using namespace std;

int test_plate_locate() {
  cout << "test_plate_locate" << endl;

  const string file = "resources/image/plate_locate.jpg";

  cv::Mat src = imread(file);

  vector<cv::Mat> resultVec;
  CPlateLocate plate;
  //plate.setDebug(0);
  //plate.setLifemode(true);

  int result = plate.plateLocate(src, resultVec);
  if (result == 0) {
    size_t num = resultVec.size();
    for (size_t j = 0; j < num; j++) {
      cv::Mat resultMat = resultVec[j];
      imshow("plate_locate", resultMat);
      waitKey(0);
    }
    destroyWindow("plate_locate");
  }

  return result;
}

int test_plate_judge() {
  cout << "test_plate_judge" << endl;

  cv::Mat src = imread("resources/image/plate_judge.jpg");

  vector<cv::Mat> matVec;
  vector<cv::Mat> resultVec;

  CPlateLocate lo;
  lo.setDebug(1);
  lo.setLifemode(true);

  int resultLo = lo.plateLocate(src, matVec);

  if (0 != resultLo) return -1;

  cout << "plate_locate_img" << endl;
  size_t num = matVec.size();
  for (size_t j = 0; j < num; j++) {
    Mat resultMat = matVec[j];
    imshow("plate_judge", resultMat);
    waitKey(0);
  }
  destroyWindow("plate_judge");

  int resultJu = PlateJudge::instance()->plateJudge(matVec, resultVec);

  if (0 != resultJu) return -1;

  cout << "plate_judge_img" << endl;
  num = resultVec.size();
  for (size_t j = 0; j < num; j++) {
    Mat resultMat = resultVec[j];
    imshow("plate_judge", resultMat);
    waitKey(0);
  }
  destroyWindow("plate_judge");

  return resultJu;
}

int test_plate_detect() {
  cout << "test_plate_detect" << endl;
  int result;
  static int ji = 0;
  
//  cv::Mat src = imread("resources/image/plate_detect.jpg");
  auto files = Utils::getFiles("resources/image/test");
  int size = files.size();
  if (0 == size) {
	  cout << "No File Found in general_test/native_test!" << endl;
	  return 0;
  }
  for (int i = 0; i < size; i++) {

		  string filepath = files[i].c_str();
		  Mat src = imread(filepath);

	  printf("---gh---66666\n");
	  vector<CPlate> resultVec;
	  CPlateDetect pd;
 
	  pd.setPDLifemode(true);

	  result = pd.plateDetect(src, resultVec);
	  if (result == 0) {
		size_t num = resultVec.size();
//		printf("num, j = %d,%d\n",num, j);
		for (size_t j = 0; j < num; j++) {
		  CPlate resultMat = resultVec[j];

	 //     imshow("plate_detect", resultMat.getPlateMat());		  
		  std::stringstream ss1(std::stringstream::in | std::stringstream::out); //gh
		  ss1 << "resources/image/tmp/Result/imgplate" << ji++ << ".jpg";
		  imwrite(ss1.str(), resultMat.getPlateMat());
	//      waitKey(0);
		}
//		destroyWindow("plate_detect");
	  }
  }
  return result;
}
/*
int test_plate_detect() {
  cout << "test_plate_detect" << endl;

  cv::Mat src = imread("resources/image/plate_detect.jpg");

  vector<CPlate> resultVec;
  CPlateDetect pd;
  pd.setPDLifemode(true);

  int result = pd.plateDetect(src, resultVec);
  if (result == 0) {
    size_t num = resultVec.size();
    for (size_t j = 0; j < num; j++) {
      CPlate resultMat = resultVec[j];

      imshow("plate_detect", resultMat.getPlateMat());
      waitKey(0);
    }
    destroyWindow("plate_detect");
  }

  return result;
}
*/

int test_plate_recognize() {
  cout << "test_plate_recognize" << endl;

  Mat src = imread("resources/image/test.jpg");

  CPlateRecognize pr;
  pr.setLifemode(true);
  pr.setDebug(false);
  pr.setMaxPlates(1);
  //pr.setDetectType(PR_DETECT_COLOR | PR_DETECT_SOBEL);
  pr.setDetectType(easypr::PR_DETECT_CMSER);

  //vector<string> plateVec;
  vector<CPlate> plateVec;

  int result = pr.plateRecognize(src, plateVec);
  //int result = pr.plateRecognizeAsText(src, plateVec);
  if (result == 0) {
    size_t num = plateVec.size();
    for (size_t j = 0; j < num; j++) {
      cout << "plateRecognize: " << plateVec[j].getPlateStr() << endl;
    }
  }

  if (result != 0) cout << "result:" << result << endl;

  return result;
}
}
}

#endif  // EASYPR_PLATE_HPP
