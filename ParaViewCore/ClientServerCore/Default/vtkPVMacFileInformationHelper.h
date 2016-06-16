/*=========================================================================

  Program:   ParaView
  Module:    vtkPVMacFileInformationHelper.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtkPVMacFileInformationHelper_h
#define vtkPVMacFileInformationHelper_h

#include "vtkPVClientServerCoreDefaultModule.h" //needed for exports
#include "vtkObject.h"

#include <string> // needed for string
#include <vector> // needed for vector of strings

// Helper class for obtaining information about Mac OS X directories and
// volumes. This is a simply utility class used only by vtkPVFileInformation
// and so does not need to be wrapped.
class VTKPVCLIENTSERVERCOREDEFAULT_EXPORT vtkPVMacFileInformationHelper : public vtkObject {
public:
  static vtkPVMacFileInformationHelper* New();
  vtkTypeMacro(vtkPVMacFileInformationHelper, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Get the home directory for the user.
  std::string GetHomeDirectory();

  // Description:
  // Get the list of mounted volumes on the Mac.
  // Returns a list of name/path pairs.
  typedef std::pair< std::string, std::string > NamePath;
  std::vector< NamePath > GetMountedVolumes();

  // Description:
  // Get the location of the application bundle.
  std::string GetBundleDirectory();

  // Description:
  // Get the location of the user's Desktop directory
  std::string GetDesktopDirectory();

  // Description:
  // Get the location of the user's Documents directory
  std::string GetDocumentsDirectory();

  // Description:
  // Get the location of the current user's Downloads directory.
  std::string GetDownloadsDirectory();

protected:
  vtkPVMacFileInformationHelper();
  virtual ~vtkPVMacFileInformationHelper();

private:
  vtkPVMacFileInformationHelper(const vtkPVMacFileInformationHelper&); // Not implemented.
  void operator=(const vtkPVMacFileInformationHelper&); // Not implemented.
};

#endif
