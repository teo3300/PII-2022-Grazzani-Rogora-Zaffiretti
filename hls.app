<project xmlns="com.autoesl.autopilot.project" name="PII-2022-Grazzani-Rogora-Zaffiretti" top="crypto_aead_encrypt">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../src/tests/genkat_aead.c" sc="0" tb="1" cflags=" -DNDEBUG -Wno-unknown-pragmas" csimflags=" -DNDEBUG -Wno-unknown-pragmas" blackbox="false"/>
        <file name="PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/printstate.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/encrypt.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

