//#include "stdafx.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include "arcsoft_face_sdk.h"
//#include "amcomdef.h"
//#include "asvloffscreen.h"
//#include "merror.h"
//#include <direct.h>
//#include <iostream>  
//#include <stdarg.h>
//#include <string>
//#include <opencv2\opencv.hpp>
//#include <vector>
//#include <time.h>
//#include <io.h>
//
//
//using namespace std;
//#pragma comment(lib, "libarcsoft_face_engine.lib")
//MHandle handle = NULL;
//MRESULT res;
//MFloat maxThreshold = 0.9;
//#define APPID "HseWycZ8Ag8gEvTcswpa9h3Gn2DX5c2nNPMEAdpUce1H"
//#define SDKKey "H87HDU2AVfWGL5oQvPqTAG67MqV8p8jXms4qd935tgF6"
//
//
//#define SafeFree(p) { if ((p)) free(p); (p) = NULL; }
//#define SafeArrayDelete(p) { if ((p)) delete [] (p); (p) = NULL; } 
//#define SafeDelete(p) { if ((p)) delete (p); (p) = NULL; } 
//
//
//vector<clock_t> time_list;
//vector<double> Accuracy;
//vector<double> Recall;
//
//
//
//void CutIplImage(IplImage* src, IplImage* dst, int x, int y)
//{
//	CvSize size = cvSize(dst->width, dst->height);
//	cvSetImageROI(src, cvRect(x, y, size.width, size.height));
//	cvCopy(src, dst);
//	cvResetImageROI(src);
//}
//
//
//void Feature_ex(IplImage* img, ASF_FaceFeature &feature)
//{
//	ASF_MultiFaceInfo detectedFaces = { 0 };
//	ASF_SingleFaceInfo SingleDetectedFaces = { 0 };
//	//IplImage* cutImg = cvCreateImage(cvSize(img->width - img->width % 4, img->height), IPL_DEPTH_8U, img->nChannels);
//	//CutIplImage(img, cutImg, 0, 0);
//	res = ASFDetectFaces(handle, img->width, img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)img->imageData, &detectedFaces);
//
//	if (MOK == res)
//	{
//		SingleDetectedFaces.faceRect.left = detectedFaces.faceRect[0].left;
//		SingleDetectedFaces.faceRect.top = detectedFaces.faceRect[0].top;
//		SingleDetectedFaces.faceRect.right = detectedFaces.faceRect[0].right;
//		SingleDetectedFaces.faceRect.bottom = detectedFaces.faceRect[0].bottom;
//		SingleDetectedFaces.faceOrient = detectedFaces.faceOrient[0];
//
//		res = ASFFaceFeatureExtract(handle, img->width, img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)img->imageData, &SingleDetectedFaces, &feature);
//		if (MOK != res)
//			printf("ASFFaceFeatureExtract fail: %d\n", res);
//	}
//	else
//		printf("ASFDetectFaces fail: %d\n", res);
//}
//
//
//void getFiles1(string path, vector<string>& files)
//{
//	//文件句柄  
//	//long hFile = 0;  //win7
//	intptr_t hFile = 0;   //win10
//						  //文件信息  
//	struct _finddata_t fileinfo;
//	string p;
//	if ((hFile = _findfirst(p.assign(path).append("\\").c_str(), &fileinfo)) != -1)
//		// "\\*"是指读取文件夹下的所有类型的文件，若想读取特定类型的文件，以png为例，则用“\\*.png”
//	{
//		do
//		{
//			//如果是目录,迭代之  
//			//如果不是,加入列表  
//			if ((fileinfo.attrib &  _A_SUBDIR))
//			{
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
//					getFiles1(p.assign(path).append("\\").append(fileinfo.name), files);
//			}
//			else
//			{
//				files.push_back(fileinfo.name);
//			}
//		} while (_findnext(hFile, &fileinfo) == 0);
//		_findclose(hFile);
//	}
//}
//
//void getFiles2(string path, vector<string>& files)
//{
//	//文件句柄  
//	//long hFile = 0;  //win7
//	intptr_t hFile = 0;   //win10
//						  //文件信息  
//	struct _finddata_t fileinfo;
//	string p;
//	if ((hFile = _findfirst(p.assign(path).append("\\*.bmp").c_str(), &fileinfo)) != -1)
//		// "\\*"是指读取文件夹下的所有类型的文件，若想读取特定类型的文件，以png为例，则用“\\*.png”
//	{
//		do
//		{
//			//如果是目录,迭代之  
//			//如果不是,加入列表  
//			if ((fileinfo.attrib &  _A_SUBDIR))
//			{
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
//					getFiles1(p.assign(path).append("\\").append(fileinfo.name), files);
//			}
//			else
//			{
//				files.push_back(fileinfo.name);
//			}
//		} while (_findnext(hFile, &fileinfo) == 0);
//		_findclose(hFile);
//	}
//}
//
//
//int main()
//{
//	res = ASFOnlineActivation(APPID, SDKKey);
//	if (MOK != res && MERR_ASF_ALREADY_ACTIVATED != res)
//		printf("ASFActivation fail: %d\n", res);
//	else
//		printf("ASFActivation sucess: %d\n", res);
//
//	ASF_ActiveFileInfo  activeFileInfo;
//	res = ASFGetActiveFileInfo(&activeFileInfo);
//	if (res != MOK)
//		printf("ASFGetActiveFileInfo fail: %d\n", res);
//
//	MInt32 mask = ASF_FACE_DETECT | ASF_FACERECOGNITION | ASF_AGE | ASF_GENDER | ASF_FACE3DANGLE | ASF_LIVENESS | ASF_IR_LIVENESS;
//	res = ASFInitEngine(ASF_DETECT_MODE_IMAGE, ASF_OP_0_ONLY, 30, 10, mask, &handle);
//	if (res != MOK)
//		printf("ASFInitEngine fail: %d\n", res);
//	else
//		printf("ASFInitEngine sucess: %d\n", res);
//
//
//	string file_path = "E:\\Pre_Work\\DataSet\\CASIA_FaceV5\\64_CASIA_FaceV5\\Register_image";
//	string search_path = file_path;
//	vector<string> file_list;
//	getFiles2(search_path, file_list);
//	/*if(file_list.empty())
//	cout << "open file error!" << endl;*/
//	vector<string> image_path;
//	for (int i = 0; i < file_list.size(); i++) {
//		image_path.push_back(file_path + "\\" + file_list[i]);
//		cout << image_path[i] << endl;;
//	}
//	random_shuffle(image_path.begin(), image_path.end());
//
//	//注册人脸特征
//	vector<ASF_FaceFeature> m_featuresVec;
//	for (int i = 0; i < image_path.size(); i++) {
//		ASF_FaceFeature feature = { 0 };
//		ASF_FaceFeature copyfeature1 = { 0 };
//		ASF_MultiFaceInfo detectedFaces = { 0 };
//		ASF_SingleFaceInfo SingleDetectedFaces = { 0 };
//		//cv::Mat image = cv::imread(image_path[i]);
//		const char* path = image_path[i].data();
//		cout << path << endl;
//		IplImage* img = cvLoadImage(path, 1);
//		IplImage* imgs;
//		CvSize size;
//		size.width = img->width - img->width % 4;
//		size.height = img->height;
//		imgs = cvCreateImage(size, img->depth, img->nChannels);
//		cvResize(img, imgs, CV_INTER_CUBIC);
//		IplImage* cut_Img = cvCreateImage(cvSize(imgs->width - imgs->width % 4, imgs->height), IPL_DEPTH_8U, imgs->nChannels);
//		CutIplImage(img, cut_Img, 0, 0);
//		//cout << img->imageData << endl;
//		//img = &IplImage(image);
//		//IplImage* cutImg = cvCreateImage(cvSize(img->width - img->width % 4, img->height), IPL_DEPTH_8U, img->nChannels);
//		//CutIplImage(img, cutImg, 0, 0);
//		res = ASFDetectFaces(handle, cut_Img->width, cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)cut_Img->imageData, &detectedFaces);
//
//		if (MOK == res)
//		{
//			SingleDetectedFaces.faceRect.left = detectedFaces.faceRect[0].left;
//			SingleDetectedFaces.faceRect.top = detectedFaces.faceRect[0].top;
//			SingleDetectedFaces.faceRect.right = detectedFaces.faceRect[0].right;
//			SingleDetectedFaces.faceRect.bottom = detectedFaces.faceRect[0].bottom;
//			SingleDetectedFaces.faceOrient = detectedFaces.faceOrient[0];
//
//			res = ASFFaceFeatureExtract(handle, cut_Img->width, cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)cut_Img->imageData, &SingleDetectedFaces, &feature);
//			if (res == MOK)
//			{
//				//拷贝feature
//				copyfeature1.featureSize = feature.featureSize;
//				copyfeature1.feature = (MByte *)malloc(feature.featureSize);
//				memset(copyfeature1.feature, 0, feature.featureSize);
//				memcpy(copyfeature1.feature, feature.feature, feature.featureSize);
//				cout << "Register Face " << i << "/ " << image_path.size() << "  " << feature.featureSize << endl;
//				m_featuresVec.push_back(copyfeature1);
//			}
//			else
//			{
//				printf("ASFFaceFeatureExtract fail: %d\n", res);
//				cout << "Register Face " << i << "/ " << image_path.size() << "  " << feature.featureSize << endl;
//				m_featuresVec.push_back(feature);
//			}
//			//cout << "Register Face " << i - Random_seed << "/500 " << "  " << feature.featureSize << endl;
//			//cout << copyfeature1.feature << endl;
//			//m_featuresVec.push_back(copyfeature1);
//
//		}
//		else
//			printf("ASFDetectFaces fail: %d\n", res);
//		//Feature_ex(img, feature);
//		//m_featuresVec.push_back(feature);
//		cvReleaseImage(&cut_Img);
//		cvReleaseImage(&img);
//		cvReleaseImage(&imgs);
//	}
//	cout << "*************************************************************************" << endl;;
//
//	//待识别人脸特征
//	double mean_error = 0;
//	for (int j = 1; j <= 10; j++) {
//		vector<ASF_FaceFeature> Recognition_featuresVec;
//
//		clock_t start = clock();
//		MFloat confidenceLevel;
//		//真实人脸特征
//		//for (int k = Random_seed; k < Random_seed + 500; k++) {
//		//	IplImage* Recognition_img = cvLoadImage(image_path[k].c_str());
//		//	ASF_MultiFaceInfo detectedFaces = { 0 };
//		//	ASF_SingleFaceInfo SingleDetectedFaces = { 0 };
//		//	ASF_FaceFeature feature = { 0 };
//		//	IplImage* Recognition_cut_Img = cvCreateImage(cvSize(Recognition_img->width - Recognition_img->width % 4, Recognition_img->height), IPL_DEPTH_8U, Recognition_img->nChannels);
//		//	CutIplImage(Recognition_img, Recognition_cut_Img, 0, 0);
//
//		//	res = ASFDetectFaces(handle, Recognition_cut_Img->width, Recognition_cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)Recognition_cut_Img->imageData, &detectedFaces);
//		//	if (MOK == res)
//		//	{
//		//		SingleDetectedFaces.faceRect.left = detectedFaces.faceRect[0].left;
//		//		SingleDetectedFaces.faceRect.top = detectedFaces.faceRect[0].top;
//		//		SingleDetectedFaces.faceRect.right = detectedFaces.faceRect[0].right;
//		//		SingleDetectedFaces.faceRect.bottom = detectedFaces.faceRect[0].bottom;
//		//		SingleDetectedFaces.faceOrient = detectedFaces.faceOrient[0];
//
//		//		res = ASFFaceFeatureExtract(handle, Recognition_cut_Img->width, Recognition_cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)Recognition_cut_Img->imageData, &SingleDetectedFaces, &feature);
//		//		Recognition_featuresVec.push_back(feature);
//		//		cout << "Real Recognition Face " << k - Random_seed << "/ 1000" << "  " << feature.featureSize << endl;
//		//		if (MOK != res)
//		//			printf("ASFFaceFeatureExtract fail: %d\n", res);
//		//	}
//		//	else
//		//	{
//		//		printf("ASFDetectFaces fail: %d\n", res);
//		//	}
//		//	cvReleaseImage(&Recognition_img);
//		//	cvReleaseImage(&Recognition_cut_Img);
//		//}
//		//cout << "*************************************************************************" << endl;;
//
//
//
//		string fake_img_path = "E:\\Pre_Work\\DataSet\\CASIA_FaceV5\\64_CASIA_FaceV5\\image";
//		vector<string> fake_file_list;
//		getFiles2(fake_img_path, fake_file_list);
//		/*if(file_list.empty())
//		cout << "open file error!" << endl;*/
//		vector<string> fake_image_path;
//		for (int i = 0; i < fake_file_list.size(); i++) {
//			fake_image_path.push_back(fake_img_path + "\\" + fake_file_list[i]);
//		}
//		random_shuffle(fake_image_path.begin(), fake_image_path.end());
//		for (int k = 0; k < 500; k++) {
//			IplImage* Recognition_img = cvLoadImage(fake_image_path[k].c_str(), 1);
//			ASF_MultiFaceInfo detectedFaces = { 0 };
//			ASF_SingleFaceInfo SingleDetectedFaces = { 0 };
//			ASF_FaceFeature feature = { 0 };
//			ASF_FaceFeature copyfeature2 = { 0 };
//			IplImage* Recognition_cut_Img = cvCreateImage(cvSize(Recognition_img->width - Recognition_img->width % 4, Recognition_img->height), IPL_DEPTH_8U, Recognition_img->nChannels);
//			CutIplImage(Recognition_img, Recognition_cut_Img, 0, 0);
//
//
//			res = ASFDetectFaces(handle, Recognition_cut_Img->width, Recognition_cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)Recognition_cut_Img->imageData, &detectedFaces);
//			if (MOK == res)
//			{
//				SingleDetectedFaces.faceRect.left = detectedFaces.faceRect[0].left;
//				SingleDetectedFaces.faceRect.top = detectedFaces.faceRect[0].top;
//				SingleDetectedFaces.faceRect.right = detectedFaces.faceRect[0].right;
//				SingleDetectedFaces.faceRect.bottom = detectedFaces.faceRect[0].bottom;
//				SingleDetectedFaces.faceOrient = detectedFaces.faceOrient[0];
//
//				res = ASFFaceFeatureExtract(handle, Recognition_cut_Img->width, Recognition_cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)Recognition_cut_Img->imageData, &SingleDetectedFaces, &feature);
//				if (res == MOK)
//				{
//					//拷贝feature
//					copyfeature2.featureSize = feature.featureSize;
//					copyfeature2.feature = (MByte *)malloc(feature.featureSize);
//					memset(copyfeature2.feature, 0, feature.featureSize);
//					memcpy(copyfeature2.feature, feature.feature, feature.featureSize);
//					cout << "Recognition Face " << k << "/500 " << "  " << feature.featureSize << endl;
//					Recognition_featuresVec.push_back(copyfeature2);
//				}
//				else
//				{
//					printf("ASFFaceFeatureExtract fail: %d\n", res);
//					cout << "Recognition Face " << k << "/500 " << "  " << feature.featureSize << endl;
//					Recognition_featuresVec.push_back(feature);
//				}
//			}
//			else
//			{
//				printf("ASFDetectFaces fail: %d\n", res);
//			}
//			if (feature.featureSize != 0) {
//				ASF_LivenessThreshold threshold = { 0 };
//				threshold.thresholdmodel_BGR = 0.75;
//				threshold.thresholdmodel_IR = 0.7;
//				res = ASFSetLivenessParam(handle, &threshold);
//				if (res != MOK)
//					printf("ASFSetLivenessParam fail: %d\n", res);
//				else
//					printf("RGB Threshold: %f  IR Threshold: %f\n", threshold.thresholdmodel_BGR, threshold.thresholdmodel_IR);
//
//				MInt32 processMask = ASF_AGE | ASF_GENDER | ASF_FACE3DANGLE | ASF_LIVENESS;
//				res = ASFProcess(handle, Recognition_cut_Img->width, Recognition_cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)Recognition_cut_Img->imageData, &detectedFaces, processMask);
//				if (res != MOK)
//					printf("ASFProcess fail: %d\n", res);
//				else
//					printf("ASFProcess sucess: %d\n", res);
//
//				ASF_AgeInfo ageInfo = { 0 };
//				res = ASFGetAge(handle, &ageInfo);
//				if (res != MOK)
//					printf("ASFGetAge fail: %d\n", res);
//				else
//					printf("Age: %d\n", ageInfo.ageArray[0]);
//
//				ASF_GenderInfo genderInfo = { 0 };
//				res = ASFGetGender(handle, &genderInfo);
//				if (res != MOK)
//					printf("ASFGetGender fail: %d\n", res);
//				else
//					printf("Gender: %d\n", genderInfo.genderArray[0]);
//
//				ASF_Face3DAngle angleInfo = { 0 };
//				res = ASFGetFace3DAngle(handle, &angleInfo);
//				if (res != MOK)
//					printf("ASFGetFace3DAngle fail: %d\n", res);
//				else
//					printf("3DAngle roll: %f   yaw: %f   pitch: %f\n", angleInfo.roll[0], angleInfo.yaw[0], angleInfo.pitch[0]);
//
//				ASF_LivenessInfo rgbLivenessInfo = { 0 };
//				res = ASFGetLivenessScore(handle, &rgbLivenessInfo);
//				if (res != MOK)
//					printf("ASFGetLivenessScore fail: %d\n", res);
//				else
//					printf("RGB Liveness: %d\n", rgbLivenessInfo.isLive[0]);
//			}
//			else {
//				printf("No Feature \n");
//			}
//			cvReleaseImage(&Recognition_img);
//			cvReleaseImage(&Recognition_cut_Img);
//		}
//		cout << "*************************************************************************" << endl;;
//
//		int tp_predicion = 0;
//		int tn_prediction = 0;
//		int fp_prediction = 0;
//		int fn_prediction = 0;
//
//		for (int j = 0; j < Recognition_featuresVec.size(); j++) {
//			for (int i = 0; i < m_featuresVec.size(); i++) {
//				res = ASFFaceFeatureCompare(handle, &m_featuresVec[i], &Recognition_featuresVec[j], &confidenceLevel);
//				if (res == MOK && (confidenceLevel > 0.8)) {
//					cout << "ASFFaceFeatureCompare success: " << (double)confidenceLevel << "  匹配号:" << i << endl;
//					cvShowImage("Recognition Face", cvLoadImage(fake_image_path[j].c_str(), 1));
//					cvShowImage("Match Face", cvLoadImage(image_path[i].c_str(), 1));
//					cvWaitKey(1000);
//					cvDestroyAllWindows();
//					break;
//				}
//				else if (res == MOK && i == Recognition_featuresVec.size()) {
//					printf("ASFFaceFeatureCompare fail: %d\n", res);
//					fp_prediction += 1;
//				}
//			}
//		}
//		cout << "Error Recognition " << fn_prediction / 5.0 << "%" << endl;
//		mean_error += fn_prediction / 5.0;
//		//计算recall值
//		/*for (int j = 0; j < Recognition_featuresVec.size(); j++) {
//		for (int i = 0; i < m_featuresVec.size(); i++)
//		{
//		res = ASFFaceFeatureCompare(handle, &m_featuresVec[i], &Recognition_featuresVec[j], &confidenceLevel);
//		if (res != MOK) {
//		if (j >= 500) {
//		printf("ASFFaceFeatureCompare fail: %d\n", res);
//		}
//		else if (j < 500 && i > 500) {
//		fn_prediction += 1;
//		break;
//		}
//		}
//		else
//		{
//		if (j < 500) {
//		printf("ASFFaceFeatureCompare sucess: %lf\n", confidenceLevel);
//		tp_predicion += 1;
//		break;
//		}
//		else {
//		fp_prediction += 1;
//		break;
//		}
//		}
//		}
//		}*/
//		clock_t end = clock();
//		cout << "Recognition Face Use " << end - start << "ms" << endl;
//		time_list.push_back(end - start);
//
//		/*ASF_LivenessThreshold threshold = { 0 };
//		threshold.thresholdmodel_BGR = 0.75;
//		threshold.thresholdmodel_IR = 0.7;
//		res = ASFSetLivenessParam(handle, &threshold);
//		if (res != MOK)
//		printf("ASFSetLivenessParam fail: %d\n", res);
//		else
//		printf("RGB Threshold: %f  IR Threshold: %f\n", threshold.thresholdmodel_BGR, threshold.thresholdmodel_IR);
//
//		MInt32 processMask = ASF_AGE | ASF_GENDER | ASF_FACE3DANGLE | ASF_LIVENESS;
//		res = ASFProcess(handle, Recognition_cut_Img->width, Recognition_cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)Recognition_cut_Img->imageData, &detectedFaces, processMask);
//		if (res != MOK)
//		printf("ASFProcess fail: %d\n", res);
//		else
//		printf("ASFProcess sucess: %d\n", res);
//
//		ASF_AgeInfo ageInfo = { 0 };
//		res = ASFGetAge(handle, &ageInfo);
//		if (res != MOK)
//		printf("ASFGetAge fail: %d\n", res);
//		else
//		printf("Age: %d\n", ageInfo.ageArray[0]);
//
//		ASF_GenderInfo genderInfo = { 0 };
//		res = ASFGetGender(handle, &genderInfo);
//		if (res != MOK)
//		printf("ASFGetGender fail: %d\n", res);
//		else
//		printf("Gender: %d\n", genderInfo.genderArray[0]);
//
//		ASF_Face3DAngle angleInfo = { 0 };
//		res = ASFGetFace3DAngle(handle, &angleInfo);
//		if (res != MOK)
//		printf("ASFGetFace3DAngle fail: %d\n", res);
//		else
//		printf("3DAngle roll: %f   yaw: %f   pitch: %f\n", angleInfo.roll[0], angleInfo.yaw[0], angleInfo.pitch[0]);
//
//		ASF_LivenessInfo rgbLivenessInfo = { 0 };
//		res = ASFGetLivenessScore(handle, &rgbLivenessInfo);
//		if (res != MOK)
//		printf("ASFGetLivenessScore fail: %d\n", res);
//		else
//		printf("RGB Liveness: %d\n", rgbLivenessInfo.isLive[0]);*/
//		//	tn_prediction = 1000 - tp_predicion - fp_prediction - fn_prediction;
//		//	cout << tp_predicion << "  " << tn_prediction << endl;
//		//	cout << "Accuracy " << (tp_predicion + tn_prediction) / 10.0  << "%" << endl;
//		//	cout << " Recall " << tp_predicion / (float)(tp_predicion + fn_prediction) / 10.0 << "%" << endl;
//		//	Accuracy.push_back((tp_predicion + tn_prediction) / 1000);
//		//	Recall.push_back(tp_predicion / (tp_predicion + fn_prediction));
//		//}
//
//		//cout << "Accuracy: " << endl;
//		//for (int k = 0; k < Accuracy.size(); k++) {
//		//	cout << Accuracy[k] << endl;
//		//}
//		//cout << "Recall: " << endl;
//		//for (int k = 0; k < Accuracy.size(); k++) {
//		//	cout << Recall[k] << endl;
//	}
//	cout << mean_error / 5.0 << endl;
//	for (int i = 0; i < time_list.size(); i++) {
//		cout << time_list[i] << " ";
//	}
//
//	const ASF_VERSION* pVersionInfo = ASFGetVersion(handle);
//	res = ASFUninitEngine(handle);
//	if (res != MOK)
//		printf("ALUninitEngine fail: %d\n", res);
//	else
//		printf("ALUninitEngine sucess: %d\n", res);
//	getchar();
//	return 0;
//}
//
