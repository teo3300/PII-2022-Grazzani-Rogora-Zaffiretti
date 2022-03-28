; ModuleID = 'H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: argmemonly noinline
define i32 @apatb_crypto_aead_encrypt_ir(i8* %c, i64* %clen, i8* %m, i64 %mlen, i8* %ad, i64 %adlen, i8* %nsec, i8* %npub, i8* %k) local_unnamed_addr #0 {
entry:
  %c_copy = alloca i8, align 512
  %clen_copy = alloca i64, align 512
  %m_copy = alloca i8, align 512
  %ad_copy = alloca i8, align 512
  %nsec_copy = alloca i8, align 512
  %npub_copy = alloca i8, align 512
  %k_copy = alloca i8, align 512
  call fastcc void @copy_in(i8* %c, i8* nonnull align 512 %c_copy, i64* %clen, i64* nonnull align 512 %clen_copy, i8* %m, i8* nonnull align 512 %m_copy, i8* %ad, i8* nonnull align 512 %ad_copy, i8* %nsec, i8* nonnull align 512 %nsec_copy, i8* %npub, i8* nonnull align 512 %npub_copy, i8* %k, i8* nonnull align 512 %k_copy)
  %0 = call i32 @apatb_crypto_aead_encrypt_hw(i8* %c_copy, i64* %clen_copy, i8* %m_copy, i64 %mlen, i8* %ad_copy, i64 %adlen, i8* %nsec_copy, i8* %npub_copy, i8* %k_copy)
  call fastcc void @copy_out(i8* %c, i8* nonnull align 512 %c_copy, i64* %clen, i64* nonnull align 512 %clen_copy, i8* %m, i8* nonnull align 512 %m_copy, i8* %ad, i8* nonnull align 512 %ad_copy, i8* %nsec, i8* nonnull align 512 %nsec_copy, i8* %npub, i8* nonnull align 512 %npub_copy, i8* %k, i8* nonnull align 512 %k_copy)
  ret i32 %0
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_in(i8* readonly, i8* noalias align 512, i64* readonly, i64* noalias align 512, i8* readonly, i8* noalias align 512, i8* readonly, i8* noalias align 512, i8* readonly, i8* noalias align 512, i8* readonly, i8* noalias align 512, i8* readonly, i8* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %1, i8* %0)
  call fastcc void @onebyonecpy_hls.p0i64(i64* align 512 %3, i64* %2)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %5, i8* %4)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %7, i8* %6)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %9, i8* %8)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %11, i8* %10)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %13, i8* %12)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0i8(i8* noalias align 512, i8* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq i8* %0, null
  %3 = icmp eq i8* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = load i8, i8* %1, align 1
  store i8 %5, i8* %0, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0i64(i64* noalias align 512, i64* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq i64* %0, null
  %3 = icmp eq i64* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = load i64, i64* %1, align 8
  store i64 %5, i64* %0, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_out(i8*, i8* noalias readonly align 512, i64*, i64* noalias readonly align 512, i8*, i8* noalias readonly align 512, i8*, i8* noalias readonly align 512, i8*, i8* noalias readonly align 512, i8*, i8* noalias readonly align 512, i8*, i8* noalias readonly align 512) unnamed_addr #3 {
entry:
  call fastcc void @onebyonecpy_hls.p0i8(i8* %0, i8* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0i64(i64* %2, i64* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %4, i8* align 512 %5)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %6, i8* align 512 %7)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %8, i8* align 512 %9)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %10, i8* align 512 %11)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %12, i8* align 512 %13)
  ret void
}

declare i32 @apatb_crypto_aead_encrypt_hw(i8*, i64*, i8*, i64, i8*, i64, i8*, i8*, i8*)

define i32 @crypto_aead_encrypt_hw_stub_wrapper(i8*, i64*, i8*, i64, i8*, i64, i8*, i8*, i8*) #4 {
entry:
  call void @copy_out(i8* null, i8* %0, i64* null, i64* %1, i8* null, i8* %2, i8* null, i8* %4, i8* null, i8* %6, i8* null, i8* %7, i8* null, i8* %8)
  %9 = call i32 @crypto_aead_encrypt_hw_stub(i8* %0, i64* %1, i8* %2, i64 %3, i8* %4, i64 %5, i8* %6, i8* %7, i8* %8)
  call void @copy_in(i8* null, i8* %0, i64* null, i64* %1, i8* null, i8* %2, i8* null, i8* %4, i8* null, i8* %6, i8* null, i8* %7, i8* null, i8* %8)
  ret i32 %9
}

declare i32 @crypto_aead_encrypt_hw_stub(i8*, i64*, i8*, i64, i8*, i64, i8*, i8*, i8*)

attributes #0 = { argmemonly noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #4 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
