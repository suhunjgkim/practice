
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"
#include <bits/stdc++.h>

using namespace std;

void simpleSortTotal1(Linked_List *list, int c);
void simpleSortTotal2(Linked_List *list, int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[200] ;
    Linked_List airportList;		// Replace array with Linked List
    int   airportCount;
    Airport* arr[30000];
    
    infile.open ("airport-codes_US.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            Airport *a = new Airport();
            infile.getline(a->code, 256, ',');
            infile.getline(cNum, 256, ',');
            string type(cNum);
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            a->longitude = atof(cNum);
            infile.getline(cNum, 256, ',');
            a->latitude = atof(cNum);
            if (type == "small_airport" || type == "medium_airport" || type == "large_airport") {
              airportList.add(a);
              arr[c] = a;
              c++;
            }
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, '\n');
            
            i++;
        }
        airportCount = c-1;
        infile.close();
        
        /*
         for (int c=0; c < airportCount; c++)
            {
                cout << airportList.get(c)->code << " long: " << airportList.get(c)->longitude << " lat: " << airportList.get(c)->latitude <<  endl;
                cout << airportList.get(c+1)->code << " long: " << airportList.get(c+1)->longitude << " lat: " << airportList.get(c+1)->latitude <<  endl;
                cout <<"Distance between " << airportList.get(c)->code << " and " << airportList.get(c+1)->code << " is "
                  << distanceEarth( airportList.get(c)->longitude, airportList.get(c)->latitude , airportList.get(c+1)->longitude, airportList.get(c+1)->latitude) << endl;
            } */
    }
    else
    {
        cout << "Error opening file";
    }

    Linked_List *list1 = new Linked_List();
    Linked_List *list2 = new Linked_List();
    int count1 = 0;
    int count2 = 0;
    
    for (int i = 0; i < airportCount; i++) {
      if (distanceEarth(airportList.get(i)->latitude, airportList.get(i)->longitude, 30.19449997, -97.66989899) > 8000) {
        list1->add(airportList.get(i));
        count1++;
      }
    }

    for (int i = 0; i < airportCount; i++) {
      if (distanceEarth(airportList.get(i)->latitude, airportList.get(i)->longitude, 30.19449997, -97.66989899) < 161) {
        list2->add(airportList.get(i));
        count2++;
      }
    }

    simpleSortTotal1(list1, count1);
    
    for(int k = 0; k < count1; k++) {
      cout << "code: " << list1->get(k)->code << endl;
      cout << "#" << k << " dist: " << distanceEarth(list1->get(k)->latitude, list1->get(k)->longitude, 30.19449997, -97.66989899)/1.61 << endl;
    }

    cout << "_________________________" << endl;

    simpleSortTotal2(list2, count2);
    
    for(int k = 0; k < count2; k++) {
      cout << "code: " << list2->get(k)->code << endl;
      cout << "#" << k << " dist: " << distanceEarth(list2->get(k)->latitude, list2->get(k)->longitude, 30.19449997, -97.66989899)/1.61 << endl;
    }
}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/*
	Provide sort routine on linked list
*/

void simpleSortTotal1(Linked_List *list, int c)
{
  for (int i = 0; i < c; i++) {
      for (int j = i; j < c; j++) {
        if (distanceEarth(list->get(i)->latitude, list->get(i)->longitude, 30.19449997, -97.66989899) < distanceEarth(list->get(j)->latitude, list->get(j)->longitude, 30.19449997, -97.66989899)) {
          list->exchg(i, j);
        }
      }
    }
}

void simpleSortTotal2(Linked_List *list, int c)
{
  for (int i = 0; i < c; i++) {
      for (int j = i; j < c; j++) {
        if (distanceEarth(list->get(i)->latitude, list->get(i)->longitude, 30.19449997, -97.66989899) > distanceEarth(list->get(j)->latitude, list->get(j)->longitude, 30.19449997, -97.66989899)) {
          list->exchg(i, j);
        }
      }
    }
}

