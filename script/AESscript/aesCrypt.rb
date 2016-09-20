#!/usr/bin/ruby
#
# Mowgli

require 'openssl'
require 'digest/sha2'
require 'base64'

class AesCrypt

    @_fileRead = nil
    @_fileOut = nil
    @_fileKey = nil

    def initialize(fileName)
        @_fileRead = File.new(fileName, "r")
        @_fileOut = "map-pawn-crypt"
        @_fileKey = "key-pawn"
        i = 0
                    
        while (File.exist?(@_fileOut + ".s") == true)
            i = i + 1
            @_fileOut = "map-pawn-crypt" + "#{i}"
        end
        @_fileOut = @_fileOut + ".s"
        puts("#{@_fileOut} create")
        
        i = 0
        while (File.exist?(@_fileKey + ".key") == true)
            i = i + 1
            @_fileKey = "map-pawn-crypt" + "#{i}"
        end
        @_fileKey = @_fileKey + ".key"
        puts("#{@_fileKey} create")
    end

    def fill()
        file = File.new(@_fileOut, "w")
        fileKey = File.new(@_fileKey, "w")

        tmp = ""
        while (line = @_fileRead.gets)
            tmp = tmp + line
        end
        cipher = OpenSSL::Cipher::AES.new(128, :CBC)
        cipher.encrypt
        key = cipher.random_key
        #iv = cipher.random_iv
        encrypted = cipher.update("24\n#{line}") + cipher.final
        file.write(encrypted)
        fileKey.write(key)
    end
end

lol = AesCrypt.new(ARGV[0])
lol.fill()
