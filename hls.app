<project xmlns="com.autoesl.autopilot.project" name="PII-2022-Grazzani-Rogora-Zaffiretti" top="crypto_aead_encrypt">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" optimizeCompile="true" clean="true" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../code_optimization/genkat_aead.c" sc="0" tb="1" cflags=" -DNDEBUG -O3 -Wno-unknown-pragmas" csimflags=" -DNDEBUG -O3 -Wno-unknown-pragmas" blackbox="false"/>
        <file name="PII-2022-Grazzani-Rogora-Zaffiretti/code_optimization/aead.c" sc="0" tb="false" cflags="-DNDEBUG -O3" csimflags="-DNDEBUG -O3" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

