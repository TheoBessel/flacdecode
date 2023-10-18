#include "vorbis.hpp"
#include "../../Utils/utils.hpp"

void VorbisBloc::read_vorbis() {
    this->read_header();
    assert(this->m_type == TYPE);
    // Get vendor length
    m_vendor_length = this->read_size(32, Order::LITTLE_ENDIAN_ORDER);
	// Get vendor string
    m_vendor_string = this->read_string(m_vendor_length);
	// Get comment list length
    m_user_comment_list_length = this->read_size(32, Order::LITTLE_ENDIAN_ORDER);
    for (uint64_t i = 0; i < m_user_comment_list_length; i++) {
		// Get comment length
        m_comment_length = this->read_size(32, Order::LITTLE_ENDIAN_ORDER);
		// Get comment string
        m_comment_string = this->read_string(m_comment_length);
		// Push comment to list
        m_user_comment_list.push_back(m_comment_string);
    }
}

void VorbisBloc::print_vorbis() {
    std::string comment;
	std::string comment_head;
	std::string comment_tail;

    std::cout << std::endl;
	std::cout << "Music infos :" << std::endl;
	std::cout << "    - Vendor      : " << m_vendor_string << std::endl;
	std::cout << "    - Comments    : " << std::endl;
	for (uint32_t i = 0; i < m_user_comment_list_length; ++i) {
		comment = m_user_comment_list[i];
		comment_head = comment.substr(0, comment.find('='));
		comment_tail = comment.substr(comment.find('=')+1, comment.length()-1);
		comment_head = capitalize(comment_head);
		std::cout << "        - " << std::setw(12) << std::left << std::setfill(' ') << comment_head << ": " << comment_tail << std::endl;
	}
	std::cout << std::endl;
}