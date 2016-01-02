#include "MeWidget.h"
#include <Qt\qdebug.h>
#include <QtGui\qvboxlayout>
#include <QtGui\qhboxlayout>
#include <MeGlWindow.h>
#include <GuiComponents\DebugSlider.h>

MeWidget::MeWidget()
{
	QVBoxLayout* mainLayout;
	setLayout(mainLayout = new QVBoxLayout);
	QVBoxLayout* controlsLayout;
	mainLayout->addLayout(controlsLayout = new QVBoxLayout);
	mainLayout->addWidget(meGlWindow = new MeGlWindow);

	QHBoxLayout* lightPositionLayout;
	controlsLayout->addLayout(lightPositionLayout = new QHBoxLayout);
	lightPositionLayout->addWidget(lightXSlider = new DebugSlider);
	lightPositionLayout->addWidget(lightYSlider = new DebugSlider);
	lightPositionLayout->addWidget(lightZSlider = new DebugSlider);

	connect(lightXSlider, SIGNAL(valueChanged(float)), 
		this, SLOT(sliderValueChanged()));
}

void MeWidget::sliderValueChanged()
{
	meGlWindow->repaint();
}