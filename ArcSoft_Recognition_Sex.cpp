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
//#include <algorithm>
//
//
//using namespace std;
//#pragma comment(lib, "libarcsoft_face_engine.lib")
//MHandle handle = NULL;
//MRESULT res;
//MFloat confidenceLevel;
//#define APPID "HseWycZ8Ag8gEvTcswpa9h3Gn2DX5c2nNPMEAdpUce1H"
//#define SDKKey "H87HDU2AVfWGL5oQvPqTAG67MqV8p8jXms4qd935tgF6"
//
//#define SafeFree(p) { if ((p)) free(p); (p) = NULL; }
//#define SafeArrayDelete(p) { if ((p)) delete [] (p); (p) = NULL; } 
//#define SafeDelete(p) { if ((p)) delete (p); (p) = NULL; } 
//
//
//vector<clock_t> time_list;
//string file_lib;
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
//void getFiles1(string path, vector<string>& files, vector<string>& register_files)
//{
//	//文件句柄  
//	//long hFile = 0;  //win7
//	intptr_t hFile = 0;   //win10
//						  //文件信息  
//	struct _finddata_t fileinfo;
//	string p;
//	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
//		// "\\*"是指读取文件夹下的所有类型的文件，若想读取特定类型的文件，以png为例，则用“\\*.png”
//	{
//		do
//		{
//			//如果是目录,迭代之  
//			//如果不是,加入列表  
//			if ((fileinfo.attrib &  _A_SUBDIR))
//			{
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
//					file_lib = fileinfo.name;
//					getFiles1(p.assign(path).append("\\").append(fileinfo.name), files, register_files);
//				}
//			}
//			else
//			{
//				if (fileinfo.name == (file_lib + "_" + "0001.jpg")) {
//					register_files.push_back(file_lib + "\\" + fileinfo.name);
//				}
//				else {
//					files.push_back(file_lib + "\\" + fileinfo.name);
//				}
//			}
//		} while (_findnext(hFile, &fileinfo) == 0);
//		_findclose(hFile);
//	}
//}
//
//void getFiles2(string path, vector<string>& files, vector<string>& register_files)
//{
//	//文件句柄  
//	//long hFile = 0;  //win7
//	intptr_t hFile = 0;   //win10
//						  //文件信息  
//	struct _finddata_t fileinfo;
//	string p;
//	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
//		// "\\*"是指读取文件夹下的所有类型的文件，若想读取特定类型的文件，以png为例，则用“\\*.png”
//	{
//		do
//		{
//			//如果是目录,迭代之  
//			//如果不是,加入列表  
//			if ((fileinfo.attrib &  _A_SUBDIR))
//			{
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
//					file_lib = fileinfo.name;
//					getFiles2(p.assign(path).append("\\").append(fileinfo.name), files, register_files);
//				}
//			}
//			else
//			{
//				if (fileinfo.name == (file_lib + "_" + "0.bmp")) {
//					register_files.push_back(file_lib + "\\" + fileinfo.name);
//				}
//				/*else if (fileinfo.name == (file_lib + "_" + "1.bmp")) {
//					register_files.push_back(file_lib + "\\" + fileinfo.name);
//				}*/
//				else {
//					files.push_back(file_lib + "\\" + fileinfo.name);
//				}
//			}
//		} while (_findnext(hFile, &fileinfo) == 0);
//		_findclose(hFile);
//	}
//}
//
//
//int main()
//{
//	int i = 0;
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
//	string file_path = "C:\\Users\\HP\\Desktop\\64_CASIA_FaceV5";
//	string jpg_file_path = "C:\\Users\\HP\\Desktop\\lfw_funneled";
//	vector<string> file_list;
//	vector<string> Register_file_list;
//	vector<string> jpg_file_list;
//	vector<string> jpg_Register_file_list;
//	getFiles2(file_path, file_list, Register_file_list);
//	getFiles1(jpg_file_path, jpg_file_list, jpg_Register_file_list);
//	vector<string> Register_image_path;
//	vector<string> image_path;
//	for (i = 0; i < Register_file_list.size(); i++) {
//		Register_image_path.push_back(file_path + "\\" + Register_file_list[i]);
//	}
//	for (i = 0; i < jpg_Register_file_list.size(); i++) {
//		Register_image_path.push_back(jpg_file_path + "\\" + jpg_Register_file_list[i]);
//	}
//	for (i = 0; i < file_list.size(); i++) {
//		image_path.push_back(file_path + "\\" + file_list[i]);
//	}
//	for (i = 0; i < jpg_file_list.size(); i++) {
//		image_path.push_back(jpg_file_path + "\\" + jpg_file_list[i]);
//	}
//
//	random_shuffle(Register_image_path.begin(), Register_image_path.end());
//	random_shuffle(image_path.begin(), image_path.end());
//	/*for (i = image_path.size(); i > 5733; i--) {
//	Register_image_path.push_back(image_path.back());
//	image_path.pop_back();
//	}*/
//
//	//注册人脸特征
//	vector<ASF_FaceFeature> male_featuresVec;
//	vector<ASF_FaceFeature> female_featuresVec;
//	vector<ASF_FaceFeature> Hard_featuresVec;
//	vector<string> male_register_image_path;
//	vector<string> female_register_image_path;
//	IplImage* img;
//	IplImage* cut_Img;
//	for (i = 0; i < Register_image_path.size(); i++) {
//		ASF_FaceFeature feature = { 0 };
//		ASF_FaceFeature copyfeature1 = { 0 };
//		ASF_MultiFaceInfo detectedFaces = { 0 };
//		ASF_SingleFaceInfo SingleDetectedFaces = { 0 };
//		ASF_GenderInfo genderInfo = { 0 };
//		const char* path = Register_image_path[i].data();
//		cout << path << endl;
//		img = cvLoadImage(path);
//		/*cvShowImage("image", img);
//		cvWaitKey(500);
//		cvDestroyAllWindows();*/
//		cut_Img = cvCreateImage(cvSize(img->width - img->width % 4, img->height), IPL_DEPTH_8U, img->nChannels);
//		CutIplImage(img, cut_Img, 0, 0);
//		res = ASFDetectFaces(handle, cut_Img->width, cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)cut_Img->imageData, &detectedFaces);
//
//		if (MOK == res)
//		{
//			SingleDetectedFaces.faceRect.left = detectedFaces.faceRect[0].left;
//			SingleDetectedFaces.faceRect.top = detectedFaces.faceRect[0].top;
//			SingleDetectedFaces.faceRect.right = detectedFaces.faceRect[0].right;
//			SingleDetectedFaces.faceRect.bottom = detectedFaces.faceRect[0].bottom;
//			SingleDetectedFaces.faceOrient = detectedFaces.faceOrient[0];
//			res = ASFFaceFeatureExtract(handle, cut_Img->width, cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)cut_Img->imageData, &SingleDetectedFaces, &feature);
//			/*cout << i << "Face Feature " << endl;
//			for (int z = 0; z < feature.featureSize; z++) {
//			cout << (unsigned int)feature.feature[z] << " ";
//			}
//			cout << endl;*/
//			if (res == MOK)
//			{
//				//拷贝feature
//				copyfeature1.featureSize = feature.featureSize;
//				copyfeature1.feature = (MByte *)malloc(feature.featureSize);
//				memset(copyfeature1.feature, 0, feature.featureSize);
//				memcpy(copyfeature1.feature, feature.feature, feature.featureSize);
//				cout << "Register Face " << i << "/ " << Register_image_path.size() << "  " << feature.featureSize << endl;
//				MInt32 processMask = ASF_GENDER;
//				res = ASFProcess(handle, cut_Img->width, cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)cut_Img->imageData, &detectedFaces, processMask);
//				if (res != MOK)
//					printf("ASFProcess fail: %d\n", res);
//				else
//					printf("ASFProcess sucess: %d\n", res);
//
//				res = ASFGetGender(handle, &genderInfo);
//				if (res != MOK)
//					printf("ASFGetGender fail: %d\n", res);
//				else {
//					printf("Gender: %d\n", genderInfo.genderArray[0]);
//					//注册人脸男性特征
//					if (genderInfo.genderArray[0] == 0) {
//						male_featuresVec.push_back(copyfeature1);
//						male_register_image_path.push_back(path);
//					}
//					//注册人脸女性特征
//					else {
//						female_featuresVec.push_back(copyfeature1);
//						female_register_image_path.push_back(path);
//					}
//				}
//			}
//			else
//			{
//				printf("ASFFaceFeatureExtract fail: %d\n", res);
//				cout << "Register Face " << i << "/ " << Register_image_path.size() << "  " << feature.featureSize << endl;
//			}
//		}
//		else
//			printf("ASFDetectFaces fail: %d\n", res);
//	}
//	cvReleaseImage(&cut_Img);
//	cvReleaseImage(&img);
//	cout << male_featuresVec.size() << "  " << female_featuresVec.size() << endl;
//	cout << "*************************************************************************" << endl;
//	Register_image_path.clear();
//	Register_image_path.shrink_to_fit();
//	cout << "Male Path" << endl;
//	for (int i = 0; i < male_register_image_path.size(); i++) {
//		cout << i << male_register_image_path[i] << endl;
//	}
//	cout << "Female Path" << endl;
//	for (int i = 0; i < female_register_image_path.size(); i++) {
//		cout << i << female_register_image_path[i] << endl;
//	}
//
//
//	//待识别人脸特征
//	for (int g = 1; g <= 10; g++) {
//		vector<ASF_FaceFeature> Recognition_featuresVec;
//		vector<int> gender;
//		clock_t start = clock();
//		random_shuffle(image_path.begin(), image_path.end());
//		for (int k = 0; k < 500; k++) {
//			IplImage* Recognition_img = cvLoadImage(image_path[k].c_str(), 1);
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
//					//记录性别，为比较时减少搜索空间使用
//					MInt32 processMask = ASF_GENDER;
//					res = ASFProcess(handle, Recognition_cut_Img->width, Recognition_cut_Img->height, ASVL_PAF_RGB24_B8G8R8, (MUInt8*)Recognition_cut_Img->imageData, &detectedFaces, processMask);
//					if (res != MOK)
//						printf("ASFProcess fail: %d\n", res);
//					else
//						printf("ASFProcess sucess: %d\n", res);
//					ASF_GenderInfo genderInfo = { 0 };
//					res = ASFGetGender(handle, &genderInfo);
//					if (res != MOK) {
//						printf("ASFGetGender fail: %d\n", res);
//						gender.push_back(-1);
//					}
//					else {
//						printf("Gender: %d\n", genderInfo.genderArray[0]);
//						gender.push_back(genderInfo.genderArray[0]);
//					}
//				}
//				else
//				{
//					printf("ASFFaceFeatureExtract fail: %d\n", res);
//					cout << "Recognition Face " << k << "/500 " << "  " << feature.featureSize << endl;
//					image_path.erase(image_path.begin() + k);
//					k--;
//				}
//			}
//			else
//			{
//				printf("ASFDetectFaces fail: %d\n", res);
//			}
//			cvReleaseImage(&Recognition_img);
//			cvReleaseImage(&Recognition_cut_Img);
//		}
//		cout << "*************************************************************************" << endl;
//
//		//Compare
//		int error = 0;
//		for (int j = 0; j < Recognition_featuresVec.size(); j++) {
//			confidenceLevel = 0;
//			double max_point = 0.00;
//			int max_point_index = 0;
//			//与男性特征比较
//			if (gender[j] == 0) {
//				for (i = 0; i < male_featuresVec.size(); i++) {
//					res = ASFFaceFeatureCompare(handle, &male_featuresVec[i], &Recognition_featuresVec[j], &confidenceLevel);
//					if (res == MOK && (confidenceLevel > max_point)) {
//						max_point = confidenceLevel;
//						max_point_index = i;
//					}
//				}
//				if (max_point > 0.9) {
//					cout << j << "/" << Recognition_featuresVec.size() << " ASFFaceFeatureCompare success: " << max_point << " 匹配号:" << max_point_index << endl;
//					cout << "Recognition Face name:" << image_path[j] << endl;
//					cout << "Match Face name:" << male_register_image_path[max_point_index] << endl;
//					if ((image_path[j].substr(0, (image_path[j].size() - 9))) != (male_register_image_path[max_point_index].substr(0, (male_register_image_path[max_point_index].size() - 9)))) {
//						cout << "Compare Fail Match Face Error" << endl;
//						error += 1;
//					}
//					/*cvShowImage("Recognition Face", cvLoadImage(image_path[j].c_str(), 1));
//					cvShowImage("Match Face", cvLoadImage(male_register_image_path[max_point_index].c_str(), 1));
//					cvWaitKey(1000);
//					cvDestroyAllWindows();*/
//					cout << "**********************Compare****************************" << endl;
//				}
//			}
//			//与女性特征比较
//			else {
//				for (i = 0; i < female_featuresVec.size(); i++) {
//					res = ASFFaceFeatureCompare(handle, &female_featuresVec[i], &Recognition_featuresVec[j], &confidenceLevel);
//					if (res == MOK && (confidenceLevel > max_point)) {
//						max_point = confidenceLevel;
//						max_point_index = i;
//					}
//				}
//				if (max_point > 0.9) {
//					cout << j << "/" << Recognition_featuresVec.size() << " ASFFaceFeatureCompare success: " << max_point << " 匹配号:" << max_point_index << endl;
//					cout << "Recognition Face name:" << image_path[j] << endl;
//					cout << "Match Face name:" << female_register_image_path[max_point_index] << endl;
//					if ((image_path[j].substr(0, (image_path[j].size() - 9))) != (female_register_image_path[max_point_index].substr(0, (female_register_image_path[max_point_index].size() - 9)))) {
//						cout << "Compare Fail Match Face Error" << endl;
//						error += 1;
//					}
//					/*cvShowImage("Recognition Face", cvLoadImage(image_path[j].c_str(), 1));
//					cvShowImage("Match Face", cvLoadImage(female_register_image_path[max_point_index].c_str(), 1));
//					cvWaitKey(1000);
//					cvDestroyAllWindows();*/
//					cout << "**********************Compare****************************" << endl;
//				}
//			}
//		}
//		clock_t end = clock();
//		cout << "Recognition Face Use " << end - start << "ms" << endl;
//		cout << "This Round Total Face Error: " << error << endl;
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
//	}
//	for (i = 0; i < time_list.size(); i++) {
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
