#!/bin/bash

if [ "$(id -u)" -ne 0 ]; then
  echo "You need to run this script with sudo!"
  exit 1
fi

cp switch /usr/local/bin

chmod +x /usr/local/bin/switch

echo "Installation completed!"