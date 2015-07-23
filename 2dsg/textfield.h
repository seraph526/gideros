#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "font.h"
#include "sprite.h"
#include "graphicsbase.h"
#include "textfieldbase.h"

#include <string>

class Application;

class TextField : public TextFieldBase
{
public:
    TextField(Application *application);
    TextField(Application *application, BMFontBase* font);
    TextField(Application *application, BMFontBase* font, const char* text);

	virtual ~TextField()
	{
		if (font_ != 0)
			font_->unref();
	}

	void setFont(Font* font);

	virtual void setText(const char* text);
	virtual const char* text() const;

	virtual void setTextColor(unsigned int color);
	virtual unsigned int textColor() const;

    virtual void setLetterSpacing(float letterSpacing);
    virtual float letterSpacing() const;

	void createGraphics();

private:
	virtual void extraBounds(float* minx, float* miny, float* maxx, float* maxy) const;

    BMFontBase* font_;

	float r_, g_, b_;
	unsigned int textColor_;
    float letterSpacing_;

private:
	GraphicsBase graphicsBase_;
    virtual void doDraw(const CurrentTransform&, float sx, float sy, float ex, float ey);
    float minx_, miny_, maxx_, maxy_;
};

#endif
