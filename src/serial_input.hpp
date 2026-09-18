#ifndef SRC_SERIAL_INPUT_HPP_
#define SRC_SERIAL_INPUT_HPP_

#include <Arduino.h>

#include "commands.hpp"
#include "constants.hpp"
#include "chip_card.hpp"

class SerialInput: public CommandSource {
public:
  SerialInput();

  commandRaw getCommandRaw() override;

  uint8_t get_menu_jump() const { return menu_jump; }
#ifdef SerialInputAsCommand
  const folderSettings& get_write_card() const { return writeCard; }
#endif
private:
#ifdef SerialInputAsCommand
  bool validateWriteCard(folderSettings& card);
#endif

  uint8_t menu_jump{};
#ifdef SerialInputAsCommand
  folderSettings writeCard{};
#endif
};

#endif /* SRC_SERIAL_INPUT_HPP_ */
