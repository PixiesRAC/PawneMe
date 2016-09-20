#!/usr/bin/ruby
#
# Mowgli

require_relative 'grammarReader.rb'

class MapGenerator

    @_grammar = nil
    @_fileOut = nil
    @_x = 0
    @_y = 0

    def initialize(grammar, x, y)
        @_grammar = grammar
        @_x = Integer(x)
        @_y = Integer(y)
        @_fileOut = "map-pawn"
        i = 0

        while (File.exist?(@_fileOut + ".map") == true)
            i = i + 1
            @_fileOut = "map-pawn" + "#{i}"
        end
        puts("#{@_fileOut} does not exist")
    end

    def getFileOut()
        return (@_fileOut)
    end

    def orderArray(array)
        arrayOrdered = []
        i = 0
        y = 0
        while (array[i] != nil)
            nb = 1
            y = i
            if (array[y + 1] != nil && array[y + 1] == array[y])
                while (array[y + 1] != nil && array[y + 1] == array[y])
                    nb = nb + 1
                    y = y + 1
                end
                arrayOrdered.push("#{array[y]}x#{nb}")
            else
                arrayOrdered.push("#{array[y]}")
            end
            i = y
            i = i + 1
        end
        return (arrayOrdered)
    end

    def displayArray(array)
        puts("---------")
        array.each { |x| puts("Value : #{x}") }
        puts("---------")
    end

    def fill()
        file = File.new("#{@_fileOut}.map" ,"w")
        file.write("#{@_x}x#{@_y}\n")
        i = 0
        arrayTmp = []
        while (i != @_x)
            randComp = @_grammar[Random.new_seed % @_grammar.length]
            arrayTmp.push(randComp)
            puts("===========> #{randComp} -- #{i} - #{@_x}")
            i = i + 1
        end
        arrayTmp = self.orderArray(arrayTmp)
        i = 0
        while (arrayTmp[i] != nil)
            file.write(arrayTmp[i])
            if (arrayTmp[i + 1] != nil)
                file.write(" ")
            end
            i = i + 1
        end
        file.write("\n")
        while (i != @_y)
            randComp = @_grammar[Random.new_seed % @_grammar.length]
            arrayTmp.push(randComp)
            puts("===========> #{randComp} -- #{i} - #{@_y}")
            i = i + 1
        end
        arrayTmp = self.orderArray(arrayTmp)
        i = 0
        while (arrayTmp[i] != nil)
            file.write(arrayTmp[i])
            if (arrayTmp[i + 1] != nil)
                file.write(" ")
            end
            i = i + 1
        end
        file.write("\n")
    end
end

test = GrammarReader.new(ARGV[0])
puts(test.getComponant)
lol = MapGenerator.new(test.getComponant, ARGV[1], ARGV[2])
lol.fill()
