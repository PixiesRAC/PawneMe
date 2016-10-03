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
        @_dir = "pawn-res"
        @_fileOut = "map-pawn-crypt"
        @_fileKey = "key-pawn"
        @_fileIV = "iv-pawn"
        i = 0
                
        while (File.directory?(@_dir) == true)
            i = i + 1
            @_dir = "pawn-res" + "#{i}"
        end
        Dir.mkdir(@_dir)
        puts("#{@_dir} create")
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
            @_fileKey = "key-pawn" + "#{i}"
        end
        @_fileKey = @_fileKey + ".key"
        puts("#{@_fileKey} create")

        i = 0
        while (File.exist?(@_fileIV + ".iv") == true)
            i = i + 1
            @_fileIV = "iv-pawn" + "#{i}"
        end
        @_fileIV = @_fileIV + ".key"
        puts("#{@_fileIV} create")
    end

    def fill()
        file = File.new("./#{@_dir}/#{@_fileOut}", "w")
        fileKey = File.new("./#{@_dir}/#{@_fileKey}", "w")
        fileIV = File.new("./#{@_dir}/#{@_fileIV}", "w")
        tmp = ""
        while (line = @_fileRead.gets)
            tmp = tmp + line
        end
        cipher = OpenSSL::Cipher::AES.new(128, :CBC)
        cipher.encrypt
        key = cipher.random_key
        iv = cipher.random_iv
        encrypted = cipher.update("24\n#{line}") + cipher.final
        file.write(encrypted)
        fileKey.write(key)
        fileIV.write(iv)
    end
end

lol = AesCrypt.new(ARGV[0])
lol.fill()
