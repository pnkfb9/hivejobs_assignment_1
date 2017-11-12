# Hivejob's client first assignment Software Design Document

## Introduction

This Software Design Document contains a description of the logical design for the First client's assignment given from Teresa Linda, Hivejobs Recruiter. The required software has been writtend in plain C, and is deployed as a Linux Command Line Application.

## Purpose

In this document a description of the key modules, custom data types, session handling and future improvements is presented.
The intended audience is the Client who wants to understand the knowledge of a junior C developer applicant.
The document will also be useful as a reference in order to install, use and remove the software from the system.

## Functional requirements

The software main functionality is to perform the computation of the mean and median values of the impedance (calculated as the square root of the sum between resistance^2 and reactance^2), starting from a list of measurement of resistances and reactances collected at different time in a given day. An example of such measurements is present in the SRS document.

Also, as the SRS states, an options.conf file is present and has to be read in order to set the language to be used and the date format type.

Expected support languages:
- Italian
- English(US)

Expected supported date formats:
- IT DD-MM-YYYY
- US MM-DD-YYYY
- AS YYYYMMDD

The software has to:
- read the configuration file and set up the enviroment with read parameters
- read an input file containing such values, as described in the SRS document given by the client
- compute mean and median impedance
- output to the console the mean and median values calculated for the day in exam.

## Assumptions

In order to avoid covering a huge set of cases not covered by the SRS, some preliminar assumptions have been made before starting the design phase.

1. the input file contains only the date of the same day(i.e. no different dates w.r.t. the first one encountered)
2. if one of the two values R and X are missing or corrupted, the entire entry is discarded from the computation
3. the date format for parsing the input date is the IT format(DD-MM-YYYY), where the parameter in options.conf describes how the output have to be formatted.

# Software Architecture

This chapter will describe the SW architecture in terms of logical blocks, custom data types and session handling.

## Logical blocks

The core of this application is founded on 4 different blocks, or modules:

### 1. Impedance Calculator

The impedance_calculator source and header files contains the functions needed to perform the computation of both mean and median values for the impedance. 

- **Mean impedance** is simply calculated as the sum of all the impedances retrieved, divided by the number of samples for the day, and it is performed by the calculate_mean_impedance method
- **Median impedance** leverages the quick sort function to sort the impedances retrieved, and if the number of samples is odd, it returns the central element of the sorted array, otherwise it returns the mean value between the object at position n/2 and n/2-1.

### 2. Read Configuration

This module, referred into the code as read_configuration.c and read_configuration.h, contains some useful methods to initialize the user context(which will e described after) with empty measurement container and with the localization parameters contained into the options.conf file. 

### 3. Read Input

The Read Input module is used to read data from the input file and store them into specificly defined data structure, referred to as 
electrical_measurements_t data type.

The structure definition is described as follows:
```
typedef struct electrical_measurements_t{

  date_t date;

  dynamic_float_array_t resistances;
  dynamic_float_array_t reactances;

  size_t num_measurements;

  float mean_impedance;
  float median_impedance;

}electrical_measurements_t;
```
and contains, other than two dynamic arrays of floating point values, representing the set of samples for Rs and Xs, the number of measurements taken and the date.

### 4. Printer

The Printer module leverages the usage of the <string.h> library to perform a ad-hoc formatting for dates and for different inputs based on the localization settings. 

It is constituted of a method called date_to_string, used to translate a date data type into a string(in the format described by the locale parameter from options.conf) and of a method print_results that formats the output ina single string that is then printed to the console.

## Custom Data Types

In order to better develop the application, there has been the need of implement custom data types:

### Dynamic arrays

This has been one of the core custom data types, and has been implemented in order to be able to store a theoretically infinite number of floating point elements into the array(standard C language does not know types such vectors). The other possible selection could be the usage of linked lists, but for the purpose of this application, dynamic arrays are sufficent.

```
typedef struct dynamic_float_array_t{

  float *array;   //pointer to a float type, holding the dynamically growing array
  size_t size;    //size of the array
  size_t used;    //used elements into the array

}dynamic_float_array_t;
```

The source file contains the implementation of a set of methods used to initialize, insert and retrieve elements from such arrays.

### User Context

This type has been defined in order to have a single-entry point in which all the user session's setting and data can be accessed.
The structure of such data type is the following:
```
typedef struct user_context_t{

  language_choice_t language;           //locale language setting
  date_format_choice_t date_format;     //date format setting

  electrical_measurements_t daily_measurement;  //daily measurements

}user_context_t;
```
The data type is autoexplicative: is composed by two custom data types for locale settings and the already seen electrical measurements data type to hold the Rs,Xs and Zs values.

This data type is also useful because eases the process of output customization with locales, having the settings bound to the user session in eery part of the code.

# Leftovers 

Unfortunately, this document cannot be finished in the given time, due to a combination of factors that are not eligible to be described here as a sort of excusatory. 

Instead, the SW engineer wants to briefly close this document with some open points and some known issues in the software developed:

### Error Handling
A simple error handling has been done, mostly a check on the inputs (if set or not, or if NULL). Only basic checks on floating point conversion from string to float has been done in order to be sure that no segfault could arise from the conversions. More could have been done, for example check on the date values for months, days and years(if the numbers are reasonable or not).
### Printing functions
Actual implementation, albeit working, is not good to see.

### Test suite

No tests have been shipped with the software. Some testing has been made locally with some different input files, with different dates and corrupted Xs and Rs values, and they passed. I know that is not a sufficent test suite(it is not at all!), I apologize.

### Future improvements 
Some improvements could be addressed in future, such as date parsing options. In fact, the program should be able to parse different type of input date(for both the three us, it and as formats). A method that tries to implement this feature has already been added, thought has only been tested for us and it locales.

Also, in order to let the user modify the options.conf file in a better way, a simple tool could be developed, with a simple command line interface, in order to easily modify settings(instead of opening the file with a text editor such as nano or vim).

