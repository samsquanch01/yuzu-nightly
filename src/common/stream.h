// Copyright 2020 yuzu Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <vector>
#include "common/common_types.h"

namespace Common {

enum class SeekOrigin {
    SetOrigin,
    FromCurrentPos,
    FromEnd,
};

class Stream {
public:
    /// Stream creates a bitstream and provides common functionality on the stream.
    explicit Stream();
    ~Stream();

    /// Reposition bitstream "cursor" to the specified offset from origin
    void Seek(s32 offset, SeekOrigin origin);

    /// Reads next byte in the stream buffer and increments position
    u8 ReadByte();

    /// Writes byte at current position
    void WriteByte(u8 byte);

    std::size_t GetPosition() const {
        return position;
    }

    std::vector<u8>& GetBuffer() {
        return buffer;
    }

    const std::vector<u8>& GetBuffer() const {
        return buffer;
    }

private:
    std::vector<u8> buffer;
    std::size_t position{0};
};

} // namespace Common
