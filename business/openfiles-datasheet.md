# OpenFiles
## Production-Grade SMB Client & Server Stack for Embedded Systems

OpenFiles is a fully independent, production-grade SMB client and server implementation designed for embedded systems and OEM integration. Independently developed — not derived from Samba, Likewise, or any open-source SMB project — it provides modern SMB2/3 protocol support, full Active Directory integration, and clean portability across embedded RTOSes, mobile OSes, and desktop platforms.

OpenFiles has shipped in production deployments across the imaging, energy, medical device, and point-of-sale industries.

---

## Key Differentiators

- **Royalty-free source license.** Standard licensing model includes full source code with no per-unit royalty, freeing OEMs from variable cost structures.
- **Clean IP — no copyleft.** Independently developed; no GPL, LGPL, or other copyleft dependencies. Streamlines OEM procurement and legal review.
- **API compatibility across versions.** OpenFiles preserves its API surface across major releases where feasible, so upgrades land as drop-in replacements rather than rewrites — a meaningful cost reduction over the life of long-lived OEM products.
- **Modern SMB2/3 with full feature set.** Encryption (AES-CCM, AES-GCM), multi-channel, DFS, Active Directory authentication, Kerberos, NTLMv2.
- **SMB server, not just client.** Unique among embedded SMB stacks; supports OEM use cases beyond traditional client-only deployments.
- **Cross-platform portability.** Same codebase runs on Windows, macOS, Linux, Android, iOS, ThreadX, NucleusPlus, VxWorks. Easily ported to additional RTOSes.
- **Actively developed.** Continuous evolution driven by both OEM customer requirements and a consumer product (GridLock) that exercises the stack against real-world workloads.

---

## Supported Platforms

**Desktop & Mobile:** Windows · macOS · Linux · Android · iOS
**Embedded RTOS:** ThreadX · NucleusPlus · VxWorks · easily ported to others

---

## Protocol & Security Capabilities

| Capability | Support |
|---|---|
| SMB versions | SMB1, SMB2.0, SMB2.1, SMB3.0, SMB3.0.2, SMB3.1.1 |
| Encryption | AES-128-CCM, AES-128-GCM (SMB 3.1.1) |
| Signing | HMAC-SHA256, AES-CMAC |
| Authentication | Kerberos, NTLMv2, NTLM |
| Active Directory | Full integration including DFS referral handling |
| Crypto backends | OpenSSL, mbedTLS, GnuTLS — configurable per build |

---

## Reference Deployments

- **Tier-1 printer OEM (HP).** OpenFiles powers SMB connectivity across HP's multi-function printer product line, shipping in volume for years.
- **Taiwan-based imaging OEM.** OpenFiles is deployed in products that are rebranded and sold under 5–10 major consumer printer brands worldwide — extending OpenFiles' reach far beyond a single OEM relationship.
- **Leading energy-sector supplier.** Production deployment for data recovery infrastructure.
- **Medical device manufacturers.** Embedded SMB integration in production medical equipment.
- **Point-of-sale device manufacturers.** Production deployments in retail terminal environments.

---

## Consumer Product Validation

Connected Way operates **GridLock** (gridlockvpn.com), an Android-first personal-cloud product. GridLock uses OpenFiles as its SMB engine — currently the **only native (JNI) Android SMB implementation** with DFS, Active Directory, and Storage Access Framework integration, and the **only Android-native SMB server**.

This continuous consumer-product use keeps OpenFiles current with modern Android storage APIs, contemporary security expectations, and real-world workloads. OEMs benefit indirectly: every feature exercised against consumer use cases hardens the codebase before it reaches OEM releases.

---

## Engagement Model

- **Standard license:** Royalty-free source license with full source-code access.
- **Alternative licensing:** Per-unit royalty, OEM-specific, and other commercial structures available on request.
- **Support tiers:** Maintenance, defect resolution, and ongoing engineering support direct from Connected Way.
- **Custom integration:** Porting to additional platforms, OEM-specific feature work, and security validation support available as professional services.
- **Evaluation:** 30-minute discovery call to assess fit, followed by NDA + evaluation license for hands-on assessment.

---

## Contact

**Connected Way**
Richard Schmitt, Founder
[email] | [phone]
connectedway.com
