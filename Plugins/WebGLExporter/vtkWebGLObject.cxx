/*=========================================================================

  Program:   ParaView Web
  Module:    vtkWebGLObject.cxx

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkWebGLObject.h"

#include "vtkMatrix4x4.h"
#include "vtkObjectFactory.h"

#include <algorithm>
#include "md5.h"

vtkStandardNewMacro(vtkWebGLObject);
#include <vector>
#include <map>


vtkWebGLObject::vtkWebGLObject()
{
  this->iswireframeMode = false;
  this->hasChanged = false;
  this->type = wTRIANGLES;
  this->hasTransparency = false;
  this->iswidget = false;
  this->interactAtServer = false;
}

vtkWebGLObject::~vtkWebGLObject()
{
}

std::string vtkWebGLObject::GetId()
{
  return this->id;
}

void vtkWebGLObject::SetId(std::string i)
{
  this->id = i;
}

void vtkWebGLObject::SetType(WebGLObjectTypes t)
  {
  this->type = t;
  }

void vtkWebGLObject::SetTransformationMatrix(vtkMatrix4x4* m)
{
  for (int i=0; i<16; i++) this->Matrix[i] = m->GetElement(i/4, i%4);
}

std::string vtkWebGLObject::GetMD5()
  {
  return this->MD5;
  }

void vtkWebGLObject::PrintSelf(ostream& os, vtkIndent indent)
  {
  this->Superclass::PrintSelf(os, indent);
  }

bool vtkWebGLObject::HasChanged()
  {
  return this->hasChanged;
  }

void vtkWebGLObject::SetWireframeMode(bool wireframe)
  {
  this->iswireframeMode = wireframe;
  }

bool vtkWebGLObject::isWireframeMode()
  {
  return this->iswireframeMode;
  }

void vtkWebGLObject::SetVisibility(bool vis)
  {
  this->isvisible = vis;
  }

bool vtkWebGLObject::isVisible()
  {
  return this->isvisible;
  }

void vtkWebGLObject::SetHasTransparency(bool t)
  {
  this->hasTransparency = t;
  }

void vtkWebGLObject::SetIsWidget(bool w)
  {
  this->iswidget = w;
  }

bool vtkWebGLObject::isWidget()
  {
  return this->iswidget;
  }

bool vtkWebGLObject::HasTransparency()
  {
  return this->hasTransparency;
  }

void vtkWebGLObject::SetRendererId(long i)
  {
  this->rendererId = i;
  }

long vtkWebGLObject::GetRendererId()
  {
  return this->rendererId;
  }

void vtkWebGLObject::SetLayer(int l)
  {
  this->layer = l;
  }

int vtkWebGLObject::GetLayer()
  {
  return this->layer;
  }

bool vtkWebGLObject::InteractAtServer()
  {
  return this->interactAtServer;
  }

void vtkWebGLObject::SetInteractAtServer(bool i)
  {
  this->interactAtServer = i;
  }

void vtkWebGLObject::GenerateBinaryData(){this->hasChanged = false;}
unsigned char* vtkWebGLObject::GetBinaryData(int vtkNotUsed(part)){return NULL;}
int vtkWebGLObject::GetBinarySize(int vtkNotUsed(part)){return 0;}
int vtkWebGLObject::GetNumberOfParts(){return 0;}
