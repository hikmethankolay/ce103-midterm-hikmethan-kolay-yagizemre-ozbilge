# Farm Management Project Library Generation and Testing

## Overview

This project is a cross platform farm management system with CMake, CTest, GoogleTest and Doxygen. It provides various coverage reports.

## Requirements

- CMake >= 3.12
- C++ Standard >= 11
- GoogleTest (for testing modules)
- Visual Studio Communit Edition for Windows Generator
- Ninja for WSL/Linux

## Setup Development Environment

### Step-1 (Run on Windows, Can Effect on WSL)

Run 1-configure-pre-commit.bat file to copy 1-pre-commit script to .git/hooks that checkes. README.md, gitignore and doxygenfiles. Also format code with astyle tool

### Step-2 (Run on Windows, Can Effect on WSL)

If gitignore missing then you can create gitignore with 2-create-git-ignore.bat file run this file.

### Step-3 (Only Windows)

Install package managers that we will use to install applications. Run 3-install-package-manager.bat to install choco and scoop package managers

### Step-4 (Only Windows)

Run 4-install-windows-enviroment.bat to install required applications. 

### Step-5 (Only WSL)

Open powershell as admin and enter WSL then goto project folder and run 4-install-wsl-environment.sh to setup WSL environment



## Generate Development Environment

You can run 9-clean-configure-app-windows.bat to generate Visual Studio Communit Edition Project of this file. Or You can use Cmake project development with Visual Studio Community Edition



## Build, Test and Package Application on Windows

Run 7-build-app-windows.bat to build, test and generate packed binaries for your application on windows.



Also you can run 7-build-doc-windows.bat to only generate documentation and 8-build-test-windows.bat to only test application. 

## Build, Test and Package Application on WSL

Run 7-build-app-linux.sh to build, test and generate packed binaries for your application on WSL environment.



## Clean Project

You can run 9-clean-project.bat to clean project outputs. 

###  Introduction
Farm Management system is a project that uses C++ with  CMake  for cross-platform support and Doxygen to document code and unit tests.

###  System Architecture
Whole management system uses fstream library with file operation functions we created for this project, Which is:

-file_read() – Reads data from file

-file_write() – Deletes all data and writes wanted data to file

-file_update() – changes specified record line

-file_line_delete() – Deletes a specified record line

-file_append() – Adds a record at the end of file

	
### Functionalities
In menu, user can see, register, update, delete a record he wants. Crop records and livestock records are contained separately which makes updating and following these records easy. If update function chosen from menu user can change any line he wants with ease even there is a million records. Same thing goes for delete function as well, user can delete a specified line or whole record if he/she wants.
These records contains information as below:

### a. Crop and livestock management: 

1)Crop records
	a-Crop’s type
	b-Crop’s plant date
	c-Crop’s harvest date
	d-Planted field area
	e-Expected harvest quantity


2)Livestock records
	a-Livestock’s type
	b-Livestock’s ear tag number
	c-Livestock’s birth date
	d-Livestock’s food
	e-Livestock's weight
	f-Is livestock dead?
		-Death date
		-Death cause

### b. Harvesting and production planning:  

3)Pest records
	a-Applied pest type
	b-Pest applied crops type
	c-Pest date
	d-Next pest date
	e-Pest area


4)İrrigation records
	a-irrigated crops type
	b-irrigation date
	c-Next irrigation date
	d-Irrigated area


### c. Equipment and vehicle maintenance: 

5)Vehicle records
	a-Vehicle’s type
	b-Vehicle’s model
	c-Vehicle’s bought date
	d-Vehicle’s last maintenance date
	e-Vehicle’s next maintenance date



6)Equipment records
	a-Equipment’s type
	b-Equipment’s model
	c-Equipment’s bought date
	d-Equipment’s last maintenance date
	e-Equipment’s next maintenance date


### d. Reporting:

7)Crop yield records
	a-Sample size of crop
	b-Sample area
	c-Actual field size
	d-Expected harvest (automatically calculate and saves it)


8)Profit records
	a-Crop
	b-Crop’s cost
	c-Expected income form crop
	d-Expected profit (automatically calculate and saves it)


9)Livestock health records
	a-Livestock’s type
	b-Livestock’s ear tag number
	c-Livestock’s known illness
	d-Livestock’s last vet check
	e-Livestock's next vet check



### Testing and Validation
We tested and documented whole system with gtest and Ctest. It has %95 coverage test and %100 success at unit test results


## Supported Platforms

![Ubuntu badge](assets/badge-ubuntu.svg)

![macOS badge](assets/badge-macos.svg)

![Windows badge](assets/badge-windows.svg)

### Test Coverage Ratios

> **Note** : There is a known bug on doxygen following badges are in different folder but has same name for this reason in doxygen html report use same image for all content [Images with same name overwrite each other in output directory · Issue #8362 · doxygen/doxygen · GitHub](https://github.com/doxygen/doxygen/issues/8362). README.md and WebPage show correct badges.

| Coverage Type | Windows OS                                                             | Linux OS (WSL-Ubuntu 20.04)                                              |
| ------------- | ---------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| Line Based    | ![Line Coverage](assets/codecoveragelibwin/badge_linecoverage.svg)     | ![Line Coverage](assets/codecoverageliblinux/badge_linecoverage.svg)     |
| Branch Based  | ![Branch Coverage](assets/codecoveragelibwin/badge_branchcoverage.svg) | ![Branch Coverage](assets/codecoverageliblinux/badge_branchcoverage.svg) |
| Method Based  | ![Method Coverage](assets/codecoveragelibwin/badge_methodcoverage.svg) | ![Method Coverage](assets/codecoverageliblinux/badge_methodcoverage.svg) |

### Documentation Coverage Ratios

|                    | Windows OS                                                        | Linux OS (WSL-Ubuntu 20.04)                                         |
| ------------------ | ----------------------------------------------------------------- | ------------------------------------------------------------------- |
| **Coverage Ratio** | ![Line Coverage](assets/doccoveragelibwin/badge_linecoverage.svg) | ![Line Coverage](assets/doccoverageliblinux/badge_linecoverage.svg) |



#### Install Test Results to HTML Converter

We are using [GitHub - inorton/junit2html: Turn Junit XML reports into self contained HTML reports](https://github.com/inorton/junit2html) to convert junit xml formatted test results to HTML page for reporting also we store logs during test. Use following commands to install this module with pip

```bash
pip install junit2html
```

### Github Actions

This project also compiled and tested with Github Actions. If there is a missing setup or problem follow github action script for both Windows and WSL under

`.github/workflows/cpp.yml`

Github actions take too much time more than 1 hour take to complete build for Windows, MacOS and Linux. Also its paid operation for this reason we use offline batch scripts easy to use. 

### Build App on Windows

We have already configured script for build operations. `7-build-app-windows.bat` have complete all required tasks and copy outputs to release folder.  

**Operation Completed in 11-15 minutes.**

- Clean project outputs

- Create required folders

- Run doxygen for documentation

- Run coverxygen for document coverage report

- Run Report Generator for Documentation Coverage Report

- Configure project for Visual Studio Community Edition

- Build Project Debug and Release

- Install/Copy Required Library and Headers

- Run Tests 

- Run OpeCppCoverage for Coverage Data Collection

- Run Reportgenerator for Test Coverage Report

- Copy output report to webpage folder

- Run mkdocs to build webpage

- Compress outputs to release folder, everything is ready for deployment. 

### Build App on WSL/Linux

We are running WSL on Windows 10 and solve our virtual machine problem. We make cross-platform development. After development before commit we run and test app on Windows and WSL with this scripts. To run on WSL you need to install WSL first. 

you can use our public notes

- https://github.com/coruhtech/vs-docker-wsl-cpp-development

- [GitHub - ucoruh/ns3-wsl-win10-setup: ns3 windows 10 WSL2 setup and usage](https://github.com/ucoruh/ns3-wsl-win10-setup)

After WSL installation, right click and open WSL bash and run `7-build-app-linux.sh` this will provide similart task with windows and will generate report and libraries on release folder. 



----

$End-Of-File$
