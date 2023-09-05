#pragma once

class ConfigGUI {

public:
	enum COLOR_STYLE {

		DARK,
		LIGHT,
		CLASSIC

	};

	enum APP_STATUS {
		ON,
		OFF
	};

	static COLOR_STYLE m_color_style;
	static APP_STATUS m_status;
};