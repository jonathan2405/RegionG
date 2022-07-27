//REGION GROWING
//Autores: Jonathan Adriano, Kevin Jimenez
//FECHA: 26 Julio 2022

#include <iostream>
#include <vector>
#include "regiongrowing.h"
#include <bits/stdc++.h>
#include <iostream>
#include <regiongrowing.cpp>
#include <memory.h>
#include "dicom/DicomReader.h"
#include "performance/benchmark.h"
#include <omp.h>

using namespace std;

int main()
{
    DicomReader dicomobj("C://Users//Jonathan//Desktop//imag.dcm");
    vector<vector<element>> vect = dicomobj.getIntImageMatrix(32);
    systemMetrics systemMetrics("regiongrowing");
    systemMetrics.resetCounters();
    vect = regiongrowing(vect);
    systemMetrics.calculate();
    systemMetrics.printMetrics();
        cout<<"RAM: " <<getRamUsage()<<"kb"<<endl;
    DicomReader::saveData(vect,"C://Users//Jonathan//Desktop//matrizresultante.txt",",",0);
    return 0;
}


