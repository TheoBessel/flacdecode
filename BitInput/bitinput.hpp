#ifndef BIT_INPUT_HPP
#define BIT_INPUT_HPP

#include <iostream>
#include <fstream>
#include <memory>

class BitInput {
public:
	BitInput(std::ifstream& input);
	void align() {
		this->m_bufferlen -= this->m_bufferlen % 8;
	}
	uint64_t read_uint(size_t n, bool update_state = true);
	int64_t read_octet(bool update_state = true);
	int64_t read_int(size_t n, bool update_state = true);
	int64_t read_rice_int(size_t n, bool update_state = true);

private:
    std::shared_ptr<std::streampos> read_state; // Public because of read_stream

private:
	std::ifstream& m_input;
	uint64_t m_bitbuffer;
	uint64_t m_bufferlen;
};

#endif // BIT_INPUT_HPP