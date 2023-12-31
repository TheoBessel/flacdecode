#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../bloc.hpp"

class ImageBloc : private Bloc {
public:
	ImageBloc(std::shared_ptr<Bloc> bloc);
    void read_image();
    void print_image();
    const uint8_t TYPE = 6;
    using Bloc::is_last;

private:
	std::shared_ptr<Bloc> m_parent_bloc;

    uint64_t m_picture_type;

	uint64_t m_mime_length = -1;
	uint64_t m_desc_length = -1;

	uint64_t m_width = -1;
	uint64_t m_height = -1;
    uint64_t m_depth = -1;
	uint64_t m_channels = -1;

	uint64_t m_data_length = -1;

	std::string m_mime_string = "No_Mime";
	std::string m_desc_string = "No_Desc";
	std::string m_data_string = "";
};

#endif // IMAGE_HPP