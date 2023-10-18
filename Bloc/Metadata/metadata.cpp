#include "metadata.hpp"

void MetadataBloc::read_metadata() {
    this->read_header();
    assert(this->m_type == TYPE);
    // Skip size informations
    this->m_inp->read_uint(80); // 16 + 16 + 24 + 24
    // Get codec informations
    m_samplerate = this->m_inp->read_uint(20);
    m_numchannels = this->m_inp->read_uint(3) + 1;
	m_sampledepth = this->m_inp->read_uint(5) + 1;
	m_numsamples = this->m_inp->read_uint(36);
	// Read the end of the block
	this->m_inp->read_uint(128);
}

void MetadataBloc::print_metadata() {
    m_time = m_numsamples/m_samplerate;

	std::cout << std::endl;
	std::cout << "Encoding infos :" << std::endl;
	std::cout << "    - Sample rate : " << m_samplerate/1000. << "kHz" << std::endl;
	std::cout << "    - Channels    : " << m_numchannels << " channel(s)" << std::endl;
	std::cout << "    - Bit rate    : " << m_sampledepth << "-bit" << std::endl;
	std::cout << "    - Duration    : " << std::setw(2) << std::setfill('0') << m_time/60 << ":" << (m_time % 60) << " min" << std::endl;
	std::cout << std::endl;
}