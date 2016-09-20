#!/usr/bin/ruby
#
# Mowgli

class GrammarReader
    
        @_file = nil
        @_componant = nil

        def returnFirstLetter(str)
            i = 0
            while (str[i] != nil && str[i] == " ")
                i = i + 1
                #puts("---> : #{i} --- #{str[i]}")
            end
            return(i)
        end
        
        def initialize(nameFile)
            @_file = File.open(nameFile, "r")
        
            while (line = @_file.gets)
                puts("===> #{line}")
                
                i = 0
                j = 0
                while(line[i] && j != -1)
                    j = returnFirstLetter(line)
                    if (line[i] == "#" || line[j] == "#")
                        j = -1
                        puts("this line is a comment : #{line}")
                    elsif (line[j] != "" && line[j] != "\n")
                        puts("this line is somehting : '#{line}' --- number #{j}")
                        puts(">>>>>#{line[j, 13]}")
                        if (line[j, 13] == "Componant ::=")
                            res = line[14, line.length]
                            puts("Componant : '#{res}'")
                            res = res.split('|')
                            j = 0
                            while (res[j] != nil)
                                res[j] = res[j].delete(' ')
                                res[j] = res[j].delete("")
                                res[j] = res[j].delete("\n")
                                j = j + 1
                            end
                            @_componant = res
                            puts("----<> '#{res}'")
                        else
                            puts("Error on grammar file")
                            return (nil)
                        end
                        j = -1
                    end
                    i = i + 1
                end
            end
        end
       
        def getComponant
            return (@_componant)
        end

        def self.finalize(id)
            @_file.close
        end
end

