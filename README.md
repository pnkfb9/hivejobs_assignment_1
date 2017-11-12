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

Mean impedance is simply calculated  
