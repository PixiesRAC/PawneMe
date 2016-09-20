#!/usr/bin/ruby

require "openssl"
require 'digest/sha2'
require 'base64'


data = "Very, very confidential data"

cipher = OpenSSL::Cipher::AES.new(128, :CBC)
cipher.encrypt
key = cipher.random_key
iv = cipher.random_iv

puts("key : \'#{key}\'")

encrypted = cipher.update(data) + cipher.final



decipher = OpenSSL::Cipher::AES.new(128, :CBC)
decipher.decrypt
decipher.key = key
decipher.iv = iv

plain = decipher.update(encrypted) + decipher.final

puts data == plain #=> true
puts("data encrypted : \'#{encrypted}\' data : #{data}")
