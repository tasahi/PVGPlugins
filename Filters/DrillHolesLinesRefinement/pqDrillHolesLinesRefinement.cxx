/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $ pqDrillHolesPointsRefinementTo.cxx $
  Author:    Arolde VIDJINNAGNI
  MIRARCO, Laurentian University
  Date:      
  Version:   0.1
  =========================================================================*/
#include "pqDrillHolesLinesRefinement.h"
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QWidget>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QSpinBox>
#include "vtkPoints.h"
//#include <QApplication>
//#include <QtGui>

	
pqDrillHolesLinesRefinement::pqDrillHolesLinesRefinement(pqProxy* pxy, QWidget* p) :
  pqLoadedFormObjectPanel(":/CustomWidget/pqDrillHolesLinesRefinement.ui", pxy, p)
  {
	  this->TypeOfRefinement = this->findChild<QComboBox*>("TypeOfRefinement");
	  this->MakeBounds = this->findChild<QCheckBox*>("MakeBounds");
	  this->Dimensions = this->findChild<QSpinBox*>("Dimensions");
	  this->MaximumLevel = this->findChild<QSpinBox*>("MaximumLevel");
	  this->MinimumLevel = this->findChild<QSpinBox*>("MinimumLevel");
	  this->Capping = this->findChild<QCheckBox*>("Capping");
	  this->NumberOfSides = this->findChild<QSpinBox*>("NumberOfSides");
	  this->Radius = this->findChild<QSpinBox*>("Radius");
	  this->OriginCx = this->findChild<QSpinBox*>("OriginCx");
	  this->OriginCy = this->findChild<QSpinBox*>("OriginCy");
	  this->OriginCz = this->findChild<QSpinBox*>("OriginCz");
	  this->SizeCx = this->findChild<QSpinBox*>("SizeCx");
	  this->SizeCy = this->findChild<QSpinBox*>("SizeCy");
	  this->SizeCz = this->findChild<QSpinBox*>("SizeCz");
	  

	  this->OriginCx->setDisabled(true);//disable by default
	  this->OriginCy->setDisabled(true);
	  this->OriginCz->setDisabled(true);
	  this->SizeCx->setDisabled(true);
	  this->SizeCy->setDisabled(true);
	  this->SizeCz->setDisabled(true);

	  this->Capping->setDisabled(true);
	  this->NumberOfSides->setDisabled(true);
	  this->Radius->setDisabled(true);

	 
	  QObject::connect(this->TypeOfRefinement, SIGNAL(currentIndexChanged(int)),
                   this, SLOT(TypeOfRefinementMenu(void)));
	  QObject::connect(this->MakeBounds, SIGNAL(stateChanged(int)),this, SLOT(MakeBoundsMenu(void)));

	  this->linkServerManagerProperties();	
}

pqDrillHolesLinesRefinement::~pqDrillHolesLinesRefinement()
{
}

void pqDrillHolesLinesRefinement::accept()
{
	pqLoadedFormObjectPanel::accept();
}

void pqDrillHolesLinesRefinement::reset()
{
  // reset widgets controlled by the parent class
	pqLoadedFormObjectPanel::reset();
}

void pqDrillHolesLinesRefinement::linkServerManagerProperties()
{
  // parent class hooks up some of our widgets in the ui
	pqLoadedFormObjectPanel::linkServerManagerProperties();

}

void pqDrillHolesLinesRefinement::MakeBoundsMenu()
{
	 	  
	if(this->MakeBounds->isChecked())
	{
	  this->OriginCx->setDisabled(true);//disable by default
	  this->OriginCy->setDisabled(true);
	  this->OriginCz->setDisabled(true);
	  this->SizeCx->setDisabled(true);
	  this->SizeCy->setDisabled(true);
	  this->SizeCz->setDisabled(true);
	}
	else
	{
	  this->OriginCx->setDisabled(false);//disable by default
	  this->OriginCy->setDisabled(false);
	  this->OriginCz->setDisabled(false);
	  this->SizeCx->setDisabled(false);
	  this->SizeCy->setDisabled(false);
	  this->SizeCz->setDisabled(false);
	}
}
void pqDrillHolesLinesRefinement::TypeOfRefinementMenu()
{
	if(this->TypeOfRefinement->currentIndex()==0)
	{
	  this->Capping->setDisabled(true);
	  this->NumberOfSides->setDisabled(true);
	  this->Radius->setDisabled(true);
    }
	else if(this->TypeOfRefinement->currentIndex()==1)
	{
	  this->Capping->setDisabled(false);
	  this->NumberOfSides->setDisabled(false);
	  this->Radius->setDisabled(false);
    }
	  
}